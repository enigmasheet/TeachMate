// Lesson 16 - Working with a whole array
// Goal: loop over an array to compute a total, average, smallest and largest.

#include <iostream>

int main()
{
    int marks[5] = {70, 85, 60, 95, 80};
    int count = 5;

    int total = 0;
    int smallest = marks[0];
    int largest = marks[0];

    for (int i = 0; i < count; i++)
    {
        total = total + marks[i];

        if (marks[i] < smallest)
            smallest = marks[i];

        if (marks[i] > largest)
            largest = marks[i];
    }

    double average = total / 5.0;

    std::cout << "Total:    " << total << "\n";
    std::cout << "Average:  " << average << "\n";
    std::cout << "Smallest: " << smallest << "\n";
    std::cout << "Largest:  " << largest << "\n";

    return 0;
}

// Try it:
//   1. Change the marks and predict the answers before you run it.
//   2. Count how many marks are 80 or more.
