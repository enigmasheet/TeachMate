// Lesson 12 - Challenge: Even or odd
// Goal: use % to test whether a number is even.

#include <iostream>

int main()
{
    int number = 0;

    std::cout << "Enter a whole number: ";
    std::cin >> number;

    if (number % 2 == 0)
        std::cout << number << " is even.\n";
    else
        std::cout << number << " is odd.\n";

    return 0;
}

// Try it:
//   1. Test with 0. Is 0 even or odd?
//   2. Also print whether the number is positive, negative or zero.
