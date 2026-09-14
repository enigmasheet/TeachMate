// Lesson 09 - Loops
// Goal: repeat work without repeating code.

#include <iostream>

int main()
{
    std::cout << "Counting from 1 to 5:\n";
    for (int i = 1; i <= 5; i++)
    {
        std::cout << i << "\n";
    }

    int n = 0;
    std::cout << "Type a number: ";
    std::cin >> n;

    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum = sum + i;
    }

    std::cout << "The sum from 1 to " << n << " is " << sum << ".\n";
    return 0;
}

// Try it:
//   1. Print only the even numbers from 2 to 10.
//   2. Make the first loop count backwards from 5 to 1.
