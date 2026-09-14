// Capstone - Stage 2a: Marks in an array
// ======================================
// Stage 1 added each number as it was typed. Now the marks are kept in an
// array, so the program can report several things about the same data.
//
// Week 2 ideas used here:
//   - a fixed-size array and a loop that walks it
//   - functions that take an array and its size
//   - <iomanip> to print a tidy average

#include <iomanip>
#include <iostream>

const int COUNT = 5;

// These functions only read the array, so the parameter is const.
// "const int marks[]" means "an array of ints"; its length is passed too.
int total(const int marks[], int count)
{
    int sum = 0;
    for (int i = 0; i < count; i++)
        sum = sum + marks[i];
    return sum;
}

int largest(const int marks[], int count)
{
    int best = marks[0];
    for (int i = 1; i < count; i++)
        if (marks[i] > best)
            best = marks[i];
    return best;
}

int smallest(const int marks[], int count)
{
    int low = marks[0];
    for (int i = 1; i < count; i++)
        if (marks[i] < low)
            low = marks[i];
    return low;
}

double average(const int marks[], int count)
{
    double divisor = count;
    return total(marks, count) / divisor;
}

int main()
{
    int marks[COUNT];

    for (int i = 0; i < COUNT; i++)
    {
        std::cout << "Enter mark " << (i + 1) << ": ";
        std::cin >> marks[i];
    }

    std::cout << "\nYou entered:\n";
    for (int i = 0; i < COUNT; i++)
        std::cout << marks[i] << "\n";

    std::cout << "\nTotal:    " << total(marks, COUNT) << "\n";
    std::cout << "Average:  " << std::fixed << std::setprecision(2)
              << average(marks, COUNT) << "\n";
    std::cout << "Largest:  " << largest(marks, COUNT) << "\n";
    std::cout << "Smallest: " << smallest(marks, COUNT) << "\n";
    return 0;
}

// Try it:
//   1. Change COUNT to 3 and read three marks.
//   2. Add a function that counts how many marks are 60 or more.
//   3. In stage2b the marks gain names: a struct groups a name with a mark,
//      and a std::vector lets the list grow while the program runs.
