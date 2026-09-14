// Lesson 14 - Nicer output with std::format
// Goal: print numbers neatly instead of gluing pieces with <<.

#include <format>
#include <iostream>

int main()
{
    int count = 3;
    double price = 12.5;

    std::cout << std::format("You have {} items.\n", count);
    std::cout << std::format("Price: {:.2f} EUR\n", price);
    std::cout << std::format("Right: {:>6}|\n", 42);
    std::cout << std::format("Left:  {:<6}|\n", "Sam");

    return 0;
}

// Try it:
//   1. Print 3.14159 with two decimals using {:.2f}.
//   2. Line up three numbers of different sizes with {:>6}.
//
// Reminder: std::format needs a recent compiler (GCC 13 or newer).
