// Lesson 07 - Arithmetic
// Goal: add, subtract, multiply, divide and get a remainder.

#include <iostream>

int main()
{
    int a = 0;
    int b = 0;

    std::cout << "Enter two whole numbers: ";
    std::cin >> a >> b;

    std::cout << a << " + " << b << " = " << a + b << "\n";
    std::cout << a << " - " << b << " = " << a - b << "\n";
    std::cout << a << " * " << b << " = " << a * b << "\n";
    std::cout << a << " / " << b << " = " << a / b << "\n";
    std::cout << a << " % " << b << " = " << a % b << "\n";
    return 0;
}

// Try it:
//   1. Try 7 and 2. Why is 7 / 2 not 3.5? (Both numbers are int.)
//   2. Try 8 and 0. What does the program do?
