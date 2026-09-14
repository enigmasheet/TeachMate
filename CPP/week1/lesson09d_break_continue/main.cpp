// Lesson 09d - break and continue
// Goal: leave a loop early or skip a round.
//
// `break`     — jumps out of the innermost loop immediately.
// `continue`  — skips the rest of the body and goes back to the top.

#include <iostream>

int main()
{
    // break — stop as soon as we see the number 7.
    std::cout << "Search for 7:\n";
    for (int i = 1; i <= 20; i++)
    {
        if (i == 7)
        {
            std::cout << "Found it!\n";
            break;               // leave the loop
        }
        std::cout << i << " ";
    }

    // continue — skip every even number.
    std::cout << "\nOdds only:\n";
    for (int i = 1; i <= 10; i++)
    {
        if (i % 2 == 0)
            continue;            // jump to next round

        std::cout << i << " ";
    }

    std::cout << "\n";

    // while (true) + break — a classic "keep going until done" pattern.
    int sum = 0;
    int n = 0;
    std::cout << "\nEnter numbers (0 to stop): ";
    while (true)
    {
        std::cin >> n;
        if (n == 0)
            break;              // the loop ends here
        sum = sum + n;
    }
    std::cout << "Total: " << sum << "\n";

    return 0;
}

// Try it:
//   1. Use `continue` to print numbers 1..20 but skip multiples of 3.
//   2. Rewrite the search loop with a `while` and `break`.
//   3. In lesson09e you put a loop inside a loop — nested loops.
