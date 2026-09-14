// Lesson 08 - Decisions with if / else
// Goal: let the program choose what to do.

#include <iostream>

int main()
{
    int mark = 0;

    std::cout << "Enter your mark (0-100): ";
    std::cin >> mark;

    if (mark >= 60)
        std::cout << "You passed.\n";
    else
        std::cout << "You did not pass.\n";

    return 0;
}

// Try it:
//   1. Add a special message when the mark is 90 or more.
//   2. Change the pass mark to 50 and test again.
