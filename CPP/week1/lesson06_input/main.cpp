// Lesson 06 - Reading input
// Goal: ask the user for a number and use it.

#include <iostream>

int main()
{
    int age = 0;

    std::cout << "How old are you? ";
    std::cin >> age;

    std::cout << "You are " << age << " years old.\n";
    return 0;
}

// Try it:
//   1. Ask for a second number and print both.
//   2. Ask for a decimal number using a double variable.
