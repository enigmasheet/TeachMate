// Capstone - Stage 4a: A generic gradebook
// ========================================
// Stage 3 ended with an object-oriented, polymorphic gradebook. Now the
// container itself becomes reusable:
//   - Repository<T>  : a template that stores a list of any type
//   - Gradebook      : keeps a Repository<Student> instead of a raw vector
//   - top()          : finds the best student with an algorithm + lambda
//
// Everything from Week 3 stays: Student, Gradebook and the abstract Report
// hierarchy are all still here.
//
// Menu:
//   1) Add   2) List   3) Average   4) Top   5) Report
//   6) Save  7) Load   8) Quit

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

// A container that can store a list of any type T.
template <typename T>
class Repository
{
private:
    std::vector<T> items;

public:
    void add(const T &item)
    {
        items.push_back(item);
    }

    int size() const
    {
        return static_cast<int>(items.size());
    }

    bool empty() const
    {
        return items.empty();
    }

    const std::vector<T> &all() const
    {
        return items;
    }

    void clear()
    {
        items.clear();
    }
};

class Student
{
private:
    std::string name;
    int mark;

public:
    Student(std::string n, int m)
    {
        name = n;
        mark = m;
        if (mark < 0)
            mark = 0;
        if (mark > 100)
            mark = 100;
    }

    std::string getName() const
    {
        return name;
    }

    int getMark() const
    {
        return mark;
    }
};

class Gradebook
{
private:
    Repository<Student> students;

public:
    void add(const Student &s)
    {
        students.add(s);
    }

    int count() const
    {
        return students.size();
    }

    double average() const
    {
        if (students.empty())
            return 0.0;

        int total = 0;
        for (const Student &s : students.all())
            total = total + s.getMark();

        double size = students.size();
        return total / size;
    }

    void list() const
    {
        if (students.empty())
        {
            std::cout << "No students yet.\n";
            return;
        }

        for (const Student &s : students.all())
            std::cout << std::left << std::setw(12) << s.getName()
                      << std::right << s.getMark() << "\n";
    }

    // Uses an algorithm plus a lambda to find the best student.
    // Only call this when count() > 0.
    Student top() const
    {
        const std::vector<Student> &all = students.all();
        auto best = std::max_element(all.begin(), all.end(),
                                     [](const Student &a, const Student &b)
                                     { return a.getMark() < b.getMark(); });
        return *best;
    }

    void save() const
    {
        std::ofstream out("students.txt");
        for (const Student &s : students.all())
            out << s.getName() << "\n" << s.getMark() << "\n";

        std::cout << "Saved " << students.size() << " student(s).\n";
    }

    void load()
    {
        std::ifstream in("students.txt");
        if (!in)
        {
            std::cout << "No saved file found.\n";
            return;
        }

        students.clear();
        std::string name;
        int mark = 0;
        while (std::getline(in, name))
        {
            in >> mark;
            in.ignore(); // drop the newline that follows the mark
            students.add(Student(name, mark));
        }

        std::cout << "Loaded " << students.size() << " student(s).\n";
    }
};

// Abstract base class: the "= 0" makes it impossible to create a plain Report.
class Report
{
public:
    virtual ~Report() {}
    virtual void print(const Gradebook &book) const = 0;
};

class SimpleReport : public Report
{
public:
    void print(const Gradebook &book) const override
    {
        book.list();
    }
};

class SummaryReport : public Report
{
public:
    void print(const Gradebook &book) const override
    {
        std::cout << "Students: " << book.count() << "\n";
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Average:  " << book.average() << "\n";
    }
};

int main()
{
    Gradebook book;
    bool running = true;

    while (running)
    {
        std::cout << "\n1) Add  2) List  3) Average  4) Top  5) Report"
                     "  6) Save  7) Load  8) Quit\n";
        std::cout << "Choice: ";

        int choice = 0;
        std::cin >> choice;

        if (choice == 1)
        {
            std::string name;
            int mark = 0;
            std::cout << "Name: ";
            std::getline(std::cin >> std::ws, name);
            std::cout << "Mark: ";
            std::cin >> mark;
            book.add(Student(name, mark));
        }
        else if (choice == 2)
            book.list();
        else if (choice == 3)
            std::cout << std::fixed << std::setprecision(2)
                      << "Average: " << book.average() << "\n";
        else if (choice == 4)
        {
            if (book.count() == 0)
                std::cout << "No students yet.\n";
            else
            {
                Student best = book.top();
                std::cout << "Top: " << best.getName()
                          << " (" << best.getMark() << ")\n";
            }
        }
        else if (choice == 5)
        {
            std::unique_ptr<Report> report;
            report = std::make_unique<SummaryReport>();
            report->print(book);
        }
        else if (choice == 6)
            book.save();
        else if (choice == 7)
            book.load();
        else if (choice == 8)
            running = false;
        else
            std::cout << "Please choose 1-8.\n";
    }

    std::cout << "Goodbye!\n";
    return 0;
}

// Try it:
//   1. Add a menu option that lists only passes (mark >= 60).
//   2. Repository is generic, so it also works for other types:
//      Repository<std::string> tags;   tags.add("senior");
//   3. In stage4b find() reports "maybe a student" with std::optional, and
//      save()/load() report problems with exceptions.
