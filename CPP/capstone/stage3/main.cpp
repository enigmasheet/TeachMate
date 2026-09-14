// Capstone - Stage 3: An object-oriented gradebook
// ================================================
// Week 1 and 2 kept the data in a struct with free functions. Now the data
// and the operations live together in classes:
//   - Student   : one student with private data
//   - Gradebook : holds every student and knows how to report and save them
//   - Report    : an abstract base; different reports print differently
//
// Menu:
//   1) Add   2) List   3) Average   4) Report   5) Save   6) Load   7) Quit

#include <fstream>
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
            std::cout << s.getName() << " - " << s.getMark() << "\n";
    }

    void save() const
    {
        std::ofstream out("students.txt");
        for (const Student &s : students)
            out << s.getName() << " " << s.getMark() << "\n";

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
        int mark;
        while (in >> name >> mark)
            students.push_back(Student(name, mark));

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
            std::cin >> name;
            std::cout << "Mark: ";
            std::cin >> mark;
            book.add(Student(name, mark));
        }
        else if (choice == 2)
            book.list();
        else if (choice == 3)
            std::cout << "Average: " << book.average() << "\n";
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
//   3. Notice how main() only talks to the Gradebook; it never touches the
//      vector directly. In Week 4 this becomes generic with templates.
