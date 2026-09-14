// Capstone - Stage 3b: A polymorphic gradebook
// ============================================
// Stage 3a bundled data and behaviour into Student and Gradebook. Now the
// way we report the gradebook is itself an object:
//   - Report        : an abstract base class (its print() is "= 0")
//   - SimpleReport  : prints the full list
//   - SummaryReport : prints the count and the average
//
// main() holds a Report through a std::unique_ptr and calls print() on the
// base class. Which version runs is decided at run time (polymorphism), and
// the unique_ptr deletes the report automatically.
//
// Menu:
//   1) Add   2) List   3) Average   4) Report   5) Save   6) Load   7) Quit

#include <fstream>
#include <iomanip>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

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
    std::vector<Student> students;

public:
    void add(const Student &s)
    {
        students.push_back(s);
    }

    int count() const
    {
        return static_cast<int>(students.size());
    }

    double average() const
    {
        if (students.empty())
            return 0.0;

        int total = 0;
        for (const Student &s : students)
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

        for (const Student &s : students)
            std::cout << std::left << std::setw(12) << s.getName()
                      << std::right << s.getMark() << "\n";
    }

    void save() const
    {
        std::ofstream out("students.txt");
        for (const Student &s : students)
            out << s.getName() << "\n" << s.getMark() << "\n";

        std::cout << "Saved " << count() << " student(s).\n";
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
            students.push_back(Student(name, mark));
        }

        std::cout << "Loaded " << count() << " student(s).\n";
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
        std::cout << "\n1) Add  2) List  3) Average  4) Report"
                     "  5) Save  6) Load  7) Quit\n";
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
            // Pick a report and call print() through the base class.
            std::unique_ptr<Report> report;
            report = std::make_unique<SummaryReport>();
            report->print(book);
        }
        else if (choice == 5)
            book.save();
        else if (choice == 6)
            book.load();
        else if (choice == 7)
            running = false;
        else
            std::cout << "Please choose 1-7.\n";
    }

    std::cout << "Goodbye!\n";
    return 0;
}

// Try it:
//   1. Change the Report option to use SimpleReport instead of SummaryReport.
//   2. Add a TopStudentReport that prints the student with the highest mark.
//   3. In stage4a the Gradebook stops owning a plain vector: a generic
//      Repository<T> stores the students, and the Report classes stay.
