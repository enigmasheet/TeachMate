// Lesson 44 - Exceptions
// Goal: report and handle errors without crashing.

#include <iostream>
#include <stdexcept>
#include <string>

double divide(double a, double b)
{
    if (b == 0)
        throw std::runtime_error("Cannot divide by zero");
    return a / b;
}

int main()
{
    try
    {
        std::cout << "10 / 2 = " << divide(10, 2) << "\n";
        std::cout << "10 / 0 = " << divide(10, 0) << "\n";
        std::cout << "This line is never reached.\n";
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << "\n";
    }

    std::cout << "The program keeps running.\n";
    return 0;
}

// Try it:
//   1. Change divide to throw when either number is negative.
//   2. Add a second catch block for a different exception type.
