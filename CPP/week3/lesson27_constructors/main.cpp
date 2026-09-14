// Lesson 27 - Constructors
// Goal: set up an object as soon as it is created.

#include <iostream>
#include <string>

class Student
{
public:
    std::string name;
    int mark;

    // A constructor has the same name as the class and no return type.
    Student(std::string n, int m)
    {
        name = n;
        mark = m;
    }

    void show()
    {
        std::cout << name << " scored " << mark << "\n";
    }
};

int main()
{
    Student one("Sam", 88);
    Student two("Mia", 95);

    one.show();
    two.show();

    return 0;
}

// Try it:
//   1. Create a third student with your own name and mark.
//   2. What happens if you write `Student three;` (no arguments)?
