// Lesson 09b - While loops
// Goal: repeat while a condition is true — when you do not know in
//       advance how many times the loop will run.
//
// A `while` checks its condition *before* every turn. If the condition
// is false the very first time, the body never executes.

#include <iostream>

int main()
{
    // Count down using while.
    int n = 5;
    std::cout << "Countdown: ";
    while (n > 0)
    {
        std::cout << n << " ";
        n--;
    }
    std::cout << "Go!\n";

    // Double until we pass 100 — we do not know the count up front.
    int value = 1;
    std::cout << "\nPowers of 2: ";
    while (value <= 100)
    {
        std::cout << value << " ";
        value = value * 2;
    }
    std::cout << "\n";

    return 0;
}

// Try it:
//   1. Ask the user for a positive number, then halve it (integer
//      division) until it reaches 0. Print each step.
//   2. Rewrite the "Powers of 2" loop with a `for` loop.
//   3. In lesson09c you meet `do…while`, which always runs at least
//      once — useful for menus and retries.
