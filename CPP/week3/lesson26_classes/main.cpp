// Lesson 26 - Classes
// Goal: bundle data and the functions that work on it into one type.

#include <iostream>
#include <string>

class Student
{
public:
    std::string name;
    int mark;

    void show()
    {
        std::cout << name << " scored " << mark << "\n";
    }
};

int main()
{
    Student one;
    one.name = "Sam";
    one.mark = 88;
    one.show();

    return 0;
}

// Try it:
//   1. Add a method `bool passed()` that returns mark >= 60.
//   2. Create a second Student and show it.
