// Lesson 19 - Structs
// Goal: group related values into one type.

#include <iostream>
#include <string>

struct Student
{
    std::string name;
    int mark;
};

int main()
{
    Student one;
    one.name = "Sam";
    one.mark = 88;

    Student two{"Mia", 95};

    std::cout << one.name << " scored " << one.mark << "\n";
    std::cout << two.name << " scored " << two.mark << "\n";

    return 0;
}

// Try it:
//   1. Create a third student and print it.
//   2. Add an `int age;` field to Student and print it.
