// Lesson 09a - For loop variations
// Goal: change how a for loop counts.
//
// The `for` header has three parts:
//     for ( start ;  keep going ;  step )
//
// All three can point in different directions.

#include <iostream>

int main()
{
    // Count down from 5 to 1.
    std::cout << "Counting down:\n";
    for (int i = 5; i >= 1; i--)
        std::cout << i << " ";

    std::cout << "\n";

    // Count by 2s from 2 to 10.
    std::cout << "Evens:\n";
    for (int i = 2; i <= 10; i += 2)
        std::cout << i << " ";

    std::cout << "\n";

    // Start in the middle and work outwards.
    std::cout << "From 3 to 8:\n";
    for (int i = 3; i <= 8; i++)
        std::cout << i << " ";

    std::cout << "\n";
    return 0;
}

// Try it:
//   1. Print the odd numbers from 1 to 15.
//   2. Count backwards from 10 to 1 by 2 (10, 8, 6, …).
//   3. In lesson09b a `while` loop handles the case when you do not know
//      how many times to loop before the program starts.
