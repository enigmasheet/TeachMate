// Lesson 15 - Arrays
// Goal: store many numbers under one name.
//
// An array has a fixed size. Positions start at 0, so for 5 items the
// positions are 0, 1, 2, 3 and 4.

#include <iostream>

int main()
{
    int marks[5] = {70, 85, 60, 95, 80};

    std::cout << "First mark: " << marks[0] << "\n";
    std::cout << "Third mark: " << marks[2] << "\n";
    std::cout << "Last mark:  " << marks[4] << "\n";

    std::cout << "All marks: ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << marks[i] << " ";
    }
    std::cout << "\n";

    return 0;
}

// Try it:
//   1. Change the marks.
//   2. Add a sixth mark and change 5 to 6 everywhere.
