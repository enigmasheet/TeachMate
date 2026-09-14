// Lesson 33 - Smart pointers
// Goal: let an object own and clean up memory for you.
//
// A std::unique_ptr owns one object and deletes it automatically.

#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Student
{
public:
    std::string name;

    Student(std::string n)
    {
        name = n;
        std::cout << "Created " << name << "\n";
    }

    ~Student()
    {
        std::cout << "Destroyed " << name << "\n";
    }
};

int main()
{
    std::vector<std::unique_ptr<Student>> students;

    students.push_back(std::make_unique<Student>("Sam"));
    students.push_back(std::make_unique<Student>("Mia"));

    for (const std::unique_ptr<Student> &s : students)
    {
        std::cout << "Student: " << s->name << "\n";
    }

    std::cout << "End of main\n";
    return 0;
} // both students are destroyed automatically

// Try it:
//   1. Predict the order of the "Destroyed" messages before running.
//   2. Add a third student.
