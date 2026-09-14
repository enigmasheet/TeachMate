// Lesson 09e - Nested loops
// Goal: a loop inside a loop — every combination of two counters.
//
// The outer loop runs once per row; the inner loop runs fully for each
// row.  If the outer runs N times and the inner M times, the body
// executes N × M times.

#include <iostream>

int main()
{
    // A 3 × 5 rectangle of stars.
    std::cout << "Rectangle:\n";
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 5; col++)
            std::cout << "* ";
        std::cout << "\n";
    }

    // A right-triangle: row i has i+1 stars.
    std::cout << "\nTriangle:\n";
    for (int row = 0; row < 5; row++)
    {
        for (int col = 0; col <= row; col++)
            std::cout << "* ";
        std::cout << "\n";
    }

    // A small times-table grid.
    std::cout << "\nTimes table (1-5):\n";
    std::cout << "    ";
    for (int c = 1; c <= 5; c++)
        std::cout << c << "  ";
    std::cout << "\n";

    for (int r = 1; r <= 5; r++)
    {
        std::cout << r << " | ";
        for (int c = 1; c <= 5; c++)
            std::cout << r * c << (r * c < 10 ? "  " : " ");
        std::cout << "\n";
    }

    return 0;
}

// Try it:
//   1. Print a 5 × 5 rectangle instead of 3 × 5.
//   2. Print an inverted triangle (5 stars on the first row, 1 on the last).
//   3. In lesson09f a challenge combines `while` and `break` to sum
//      numbers until the user types 0.
