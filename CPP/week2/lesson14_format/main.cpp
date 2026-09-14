// Lesson 14 - Formatting output with <iomanip>
// Goal: control decimals, width and alignment when printing with std::cout.

#include <iomanip>
#include <iostream>
#include <string>

int main()
{
    int count = 3;
    double price = 12.5;

    std::cout << "You have " << count << " items.\n";

    // fixed + setprecision(2) -> always two digits after the decimal point.
    std::cout << "Price: " << std::fixed << std::setprecision(2)
              << price << " EUR\n";

    // setw sets the width of the NEXT item only (right-aligned by default).
    std::cout << "Right: |" << std::setw(6) << 42 << "|\n";
    std::cout << "Left:  |" << std::left << std::setw(6) << "Sam" << "|\n";

    return 0;
}

// Try it:
//   1. Print 3.14159 with two decimals.
//   2. Line up three numbers of different sizes using std::setw(6).
//
// Note: setprecision and left/right stay in effect once set; setw applies to
// one item only. Use std::right to switch alignment back.
