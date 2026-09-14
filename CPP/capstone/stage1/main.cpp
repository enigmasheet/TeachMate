// Capstone - Stage 1: Average of three marks
// ==========================================
// The first layer of the course project. It uses only Week 1 ideas:
// variables, input, a loop, arithmetic and output.
//
// It asks for three marks, adds them up, and prints the total and average.

#include <iostream>

int main()
{
    int total = 0;

    for (int i = 1; i <= 3; i++)
    {
        int mark = 0;
        std::cout << "Enter mark " << i << ": ";
        std::cin >> mark;
        total = total + mark;
    }

    // Dividing by 3.0 (not 3) gives a decimal answer.
    double average = total / 3.0;

    std::cout << "\nTotal marks: " << total << "\n";
    std::cout << "Average: " << average << "\n";
    return 0;
}

// Try it:
//   1. Read five marks instead of three.
//   2. Print the message "Pass" when the average is 60 or more.
//   3. In Week 2 this program grows: it will store the marks in an array
//      and let the user keep adding scores through a menu.
