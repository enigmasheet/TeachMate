// Capstone - Stage 2: Student gradebook with a file
// =================================================
// This layer combines Week 1 and Week 2 ideas:
//   - a struct (Student), a std::vector, loops and functions
//   - a simple if/else menu
//   - reading and writing a text file so data survives
//
// Menu:
//   1) Add a student   2) List students   3) Show the average
//   4) Save to file    5) Load from file  6) Quit

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

struct Student
{
    std::string name;
    int mark;
};

void addStudent(std::vector<Student> &students)
{
    Student s;
    std::cout << "Name: ";
    std::cin >> s.name;
    std::cout << "Mark: ";
    std::cin >> s.mark;
    students.push_back(s);
    std::cout << "Added " << s.name << ".\n";
}

void listStudents(const std::vector<Student> &students)
{
    if (students.empty())
    {
        std::cout << "No students yet.\n";
        return;
    }

    // const & means "look at each student without copying or changing it".
    for (const Student &s : students)
    {
        std::cout << s.name << " - " << s.mark << "\n";
    }
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

    std::cout << "Average mark: " << average << "\n";
}

void saveToFile(const std::vector<Student> &students)
{
    std::ofstream out("students.txt");
    for (const Student &s : students)
        out << s.name << " " << s.mark << "\n";

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
    while (in >> s.name >> s.mark)
        students.push_back(s);

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
//   3. In Week 3 this grows again: Student becomes a class that protects
//      its data, and the gradebook gets its own class.
