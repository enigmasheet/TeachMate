// Capstone - Stage 2b: Student gradebook with a file
// ==================================================
// Stage 2a kept the marks in an array of plain ints. Now each mark gets a
// name, and the list can grow while the program runs. This layer combines
// all of Week 2:
//   - a struct (Student) that groups related fields
//   - a std::vector that can grow with push_back
//   - functions that take the vector by reference so they can change it
//   - std::getline so names may contain spaces
//   - reading and writing a text file so data survives
//
// Menu:
//   1) Add a student   2) List students   3) Show the average
//   4) Save to file    5) Load from file  6) Quit

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

struct Student
{
    std::string name;
    int mark;
};

// The & means the function works on the caller's vector directly.
// It has no const, because we push a new student into it.
void addStudent(std::vector<Student> &students)
{
    Student s;
    std::cout << "Name: ";
    std::getline(std::cin >> std::ws, s.name);
    std::cout << "Mark: ";
    std::cin >> s.mark;
    students.push_back(s);
    std::cout << "Added " << s.name << ".\n";
}

// const & means "look at the caller's vector without copying or changing it".
void listStudents(const std::vector<Student> &students)
{
    if (students.empty())
    {
        std::cout << "No students yet.\n";
        return;
    }

    for (const Student &s : students)
        std::cout << std::left << std::setw(12) << s.name
                  << std::right << s.mark << "\n";
}

void showAverage(const std::vector<Student> &students)
{
    if (students.empty())
    {
        std::cout << "No students yet.\n";
        return;
    }

    int total = 0;
    for (const Student &s : students)
        total = total + s.mark;

    double count = students.size();
    double average = total / count;

    std::cout << std::fixed << std::setprecision(2)
              << "Average mark: " << average << "\n";
}

void saveToFile(const std::vector<Student> &students)
{
    std::ofstream out("students.txt");
    for (const Student &s : students)
        out << s.name << "\n" << s.mark << "\n";

    std::cout << "Saved " << students.size() << " student(s).\n";
}

void loadFromFile(std::vector<Student> &students)
{
    std::ifstream in("students.txt");
    if (!in)
    {
        std::cout << "No saved file found.\n";
        return;
    }

    students.clear();
    Student s;
    while (std::getline(in, s.name))
    {
        in >> s.mark;
        in.ignore(); // drop the newline that follows the mark
        students.push_back(s);
    }

    std::cout << "Loaded " << students.size() << " student(s).\n";
}

int main()
{
    std::vector<Student> students;
    bool running = true;

    while (running)
    {
        std::cout << "\n1) Add  2) List  3) Average  4) Save  5) Load  6) Quit\n";
        std::cout << "Choice: ";

        int choice = 0;
        std::cin >> choice;

        if (choice == 1)
            addStudent(students);
        else if (choice == 2)
            listStudents(students);
        else if (choice == 3)
            showAverage(students);
        else if (choice == 4)
            saveToFile(students);
        else if (choice == 5)
            loadFromFile(students);
        else if (choice == 6)
            running = false;
        else
            std::cout << "Please choose 1-6.\n";
    }

    std::cout << "Goodbye!\n";
    return 0;
}

// Try it:
//   1. Add a menu option to print only students with a mark of 80 or more.
//   2. Add a function to find the best mark.
//   3. In stage3a the data and the operations move together into classes:
//      Student protects its data, and a Gradebook owns the whole vector.
