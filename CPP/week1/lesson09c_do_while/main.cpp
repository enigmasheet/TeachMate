// Lesson 09c - Do-while loops
// Goal: a loop that always runs at least once, then checks the condition.
//
//     do {
//         body
//     } while (condition);   ← note the semicolon
//
// Useful when you must show the body before you know whether to repeat:
// menus, retry prompts, "play again?".

#include <iostream>

int main()
{
    int number = 0;

    do
    {
        std::cout << "Enter a number greater than 0: ";
        std::cin >> number;
    }
    while (number <= 0);

    std::cout << "You entered " << number << ".\n";

    return 0;
}

// Try it:
//   1. Ask the user to type a single digit (0-9). If they type something
//      else, ask again until it is valid.
//   2. Rewrite the loop using `while (true)` + `break` — which do you
//      find clearer?  (lesson09d covers `break`.)
