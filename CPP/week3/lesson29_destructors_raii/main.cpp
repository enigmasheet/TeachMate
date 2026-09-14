// Lesson 29 - Destructors and RAII
// Goal: see exactly when an object is created and destroyed.
//
// RAII = Resource Acquisition Is Initialization. An object cleans up after
// itself automatically when it goes out of scope.

#include <iostream>
#include <string>

class Tracer
{
public:
    std::string name;

    Tracer(std::string n) : name(n) // ": name(n)" is a member init list
    {
        std::cout << "Created " << name << "\n";
    }

    ~Tracer() // a destructor runs just before the object disappears
    {
        std::cout << "Destroyed " << name << "\n";
    }
};

int main()
{
    Tracer first("first");

    {
        Tracer inner("inner");
        std::cout << "inside the block\n";
    } // "inner" is destroyed here

    std::cout << "back in main\n";
    return 0;
} // "first" is destroyed here

// Try it:
//   1. Predict the exact order of the messages before you run it.
//   2. Add a third Tracer inside the block.
