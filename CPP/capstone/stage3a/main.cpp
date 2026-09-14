// Capstone - Stage 3a: An object-oriented gradebook
// =================================================
// Stages 1 and 2 kept the data in a struct with free functions. Now the
// data and the operations live together in classes:
//   - Student   : one student, with private data and a constructor that
//                 keeps the mark inside 0..100
//   - Gradebook : owns the vector of students and knows how to report and
//                 save them (its destructor cleans up automatically)
//
// Menu:
//   1) Add   2) List   3) Average   4) Save   5) Load   6) Quit

#include <fstream>
#include <iomanip>
#include <iostream>
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

int main()
{
    Gradebook book;
    bool running = true;

    while (running)
    {
        std::cout << "\n1) Add  2) List  3) Average  4) Save  5) Load  6) Quit\n";
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
            book.save();
        else if (choice == 5)
            book.load();
        else if (choice == 6)
            running = false;
        else
            std::cout << "Please choose 1-6.\n";
    }

    std::cout << "Goodbye!\n";
    return 0;
}

// Try it:
//   1. Give Student a setName() that rejects empty names.
//   2. Add a Gradebook method best() that returns the highest mark.
//   3. In stage3b a Report class hierarchy prints the gradebook in more
//      than one way, chosen at run time through a base-class pointer.
