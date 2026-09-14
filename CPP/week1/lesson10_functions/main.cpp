// Lesson 10 - Functions
// Goal: give a block of work a name so you can reuse it.

#include <iostream>

// This function takes a number and returns its square.
int square(int x)
{
    return x * x;
}

int main()
{
    std::cout << "square(3)  = " << square(3) << "\n";
    std::cout << "square(5)  = " << square(5) << "\n";
    std::cout << "square(10) = " << square(10) << "\n";
    return 0;
}

// Try it:
//   1. Write a function `int cube(int x)` that returns x * x * x.
//   2. Write a function that adds two numbers.
