// Lesson 09g - Challenge: Star triangle
// Goal: use nested loops to print a growing pattern of stars.
//
// This lesson combines:
//   - two `for` loops (nested)
//   - the relationship between the row number and the number of stars

#include <iostream>

int main()
{
    int rows = 0;
    std::cout << "How many rows? ";
    std::cin >> rows;

    // Right-aligned triangle: row i has i+1 stars.
    std::cout << "\nRight-aligned:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <= i; j++)
            std::cout << "* ";
        std::cout << "\n";
    }

    // Centre-aligned (pyramid): spaces then stars.
    // Row i needs (rows-i-1) spaces followed by (2*i+1) stars.
    std::cout << "\nCentre-aligned:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int s = 0; s < rows - i - 1; s++)
            std::cout << " ";
        for (int j = 0; j < 2 * i + 1; j++)
            std::cout << "*";
        std::cout << "\n";
    }

    // Inverted: row i shows (rows-i) stars.
    std::cout << "\nInverted:\n";
    for (int i = rows; i >= 1; i--)
    {
        for (int j = 0; j < i; j++)
            std::cout << "* ";
        std::cout << "\n";
    }

    return 0;
}

// Try it:
//   1. Change the triangle to use a different character, e.g. `#`.
//   2. Print a diamond of height 2*rows-1 by combining the upright
//      and inverted triangles (without duplicating code — keep it simple).
//   3. You now have every basic loop form. In lesson10 you learn how to
//      package work into a reusable function.
