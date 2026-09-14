// Lesson 13 - Challenge: Times table
// Goal: use a loop to print a times table.

#include <iostream>

int main()
{
    int table = 5;

    for (int i = 1; i <= 10; i++)
    {
        std::cout << table << " x " << i << " = " << table * i << "\n";
    }

    return 0;
}

// Try it:
//   1. Change table to 7.
//   2. Ask the user which table they want, using std::cin.
