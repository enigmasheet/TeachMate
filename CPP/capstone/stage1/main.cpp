// Capstone - Stage 1: Average of three marks
// ==========================================
// The first layer of the course project. It uses only Week 1 ideas:
// variables, input, a loop, one small function, arithmetic and output.
//
// It asks for three marks, adds them up, and prints the total and average.

#include <iostream>

// A function keeps the arithmetic in one named place.
double average(int total, int count)
{
    double divisor = count;
    return total / divisor;
}

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

    std::cout << "\nTotal marks: " << total << "\n";
    std::cout << "Average: " << average(total, 3) << "\n";
    return 0;
}

// Try it:
//   1. Read five marks instead of three.
//   2. Print the message "Pass" when the average is 60 or more.
//   3. In stage2a the marks move into an array, so the program can keep
//      them and report more than just the average.
