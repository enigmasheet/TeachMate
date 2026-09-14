// Capstone - Stage 4b: A generic, modern gradebook (final)
// =======================================================
// The last layer ties the whole course together. Every earlier idea is
// still here, and Week 4 adds the modern pieces:
//   - templates        : Repository<T> works for any type
//   - algorithms/lambda: top() finds the best student
//   - optional         : top() and find() may return "no student"
//   - exceptions       : save()/load() report problems safely
//   - move semantics   : std::move avoids copying a student into the list
//   - <iomanip>        : tidy, aligned output
//   - classes/polymorphism: Student, Gradebook and the Report hierarchy
//
// Menu:
//   1) Add   2) List   3) Average   4) Top   5) Find
//   6) Report   7) Save   8) Load   9) Quit

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <memory>
#include <optional>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

// A container that can store a list of any type T.
// add() takes its item by value and then moves it in, so the copy made by
// the caller is reused instead of copied again.
template <typename T>
class Repository
{
private:
    std::vector<T> items;

public:
    void add(T item)
    {
        items.push_back(std::move(item));
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
    // Take the student by value, then std::move it into the repository.
    void add(Student s)
    {
        students.add(std::move(s));
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

    // Uses an algorithm plus a lambda; the optional says "maybe a student".
    std::optional<Student> top() const
    {
        if (students.empty())
            return std::nullopt;

        const std::vector<Student> &all = students.all();
        auto best = std::max_element(all.begin(), all.end(),
                                     [](const Student &a, const Student &b)
                                     { return a.getMark() < b.getMark(); });
        return *best;
    }

    std::optional<Student> find(const std::string &name) const
    {
        for (const Student &s : students.all())
            if (s.getName() == name)
                return s;

        return std::nullopt;
    }

    void save() const
    {
        std::ofstream out("students.txt");
        if (!out)
            throw std::runtime_error("Could not open students.txt for writing");

        for (const Student &s : students.all())
            out << s.getName() << "\n" << s.getMark() << "\n";

        std::cout << "Saved " << students.size() << " student(s).\n";
    }

    void load()
    {
        std::ifstream in("students.txt");
        if (!in)
            throw std::runtime_error("No saved file found (students.txt)");

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
        std::cout << "\n1) Add  2) List  3) Average  4) Top  5) Find"
                     "  6) Report  7) Save  8) Load  9) Quit\n";
        std::cout << "Choice: ";

        int choice = 0;
        std::cin >> choice;

        try
        {
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
                std::optional<Student> best = book.top();
                if (best.has_value())
                    std::cout << "Top: " << best->getName()
                              << " (" << best->getMark() << ")\n";
                else
                    std::cout << "No students yet.\n";
            }
            else if (choice == 5)
            {
                std::string name;
                std::cout << "Name to find: ";
                std::getline(std::cin >> std::ws, name);

                std::optional<Student> found = book.find(name);
                if (found.has_value())
                    std::cout << found->getName() << " scored "
                              << found->getMark() << "\n";
                else
                    std::cout << "Not found.\n";
            }
            else if (choice == 6)
            {
                std::unique_ptr<Report> report;
                report = std::make_unique<SummaryReport>();
                report->print(book);
            }
            else if (choice == 7)
                book.save();
            else if (choice == 8)
                book.load();
            else if (choice == 9)
                running = false;
            else
                std::cout << "Please choose 1-9.\n";
        }
        catch (const std::exception &e)
        {
            std::cout << "Error: " << e.what() << "\n";
        }
    }

    std::cout << "Goodbye!\n";

    // Repository is generic, so it also works for other types:
    //   Repository<std::string> tags;
    //   tags.add("senior");
    return 0;
}

// Try it:
//   1. Add a menu option that lists only passes (mark >= 60).
//   2. Try loading before saving to see the exception message.
//   3. Add a Repository<std::string> for tags and print each tag.
