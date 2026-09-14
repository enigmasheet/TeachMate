// Lesson 28 - Hiding data (encapsulation)
// Goal: keep data private and change it only through methods.
//
// "private" means the data can only be used inside the class.

#include <iostream>
#include <string>

class Student
{
private:
    std::string name;
    int mark;

public:
    Student(std::string n, int m)
    {
        name = n;
        setMark(m);
    }

    void setMark(int m)
    {
        if (m < 0)
            m = 0;
        if (m > 100)
            m = 100;
        mark = m;
    }

    int getMark() const
    {
        return mark;
    }

    void show() const
    {
        std::cout << name << " scored " << mark << "\n";
    }
};

int main()
{
    Student sam("Sam", 88);
    sam.show();

    sam.setMark(150); // too big, so it is clamped to 100
    std::cout << "After setMark(150): " << sam.getMark() << "\n";

    // sam.mark = 50;  // ERROR: mark is private

    return 0;
}

// Try it:
//   1. Uncomment the last line and read the error message.
//   2. Test setMark(-10).
