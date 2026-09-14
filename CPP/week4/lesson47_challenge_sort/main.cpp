// Lesson 47 - Challenge: Sort students by mark
// Goal: use a class, a vector, an algorithm and a lambda together.

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Student
{
public:
    std::string name;
    int mark;

    Student(std::string n, int m)
    {
        name = n;
        mark = m;
    }
};

int main()
{
    std::vector<Student> students = {
        Student("Sam", 88),
        Student("Mia", 95),
        Student("Ada", 79)};

    // Sort from highest mark to lowest.
    std::sort(students.begin(), students.end(),
              [](const Student &a, const Student &b)
              { return a.mark > b.mark; });

    for (const Student &s : students)
        std::cout << s.name << ": " << s.mark << "\n";

    return 0;
}

// Try it:
//   1. Sort by name instead of by mark.
//   2. Print only the students who scored 85 or more.
