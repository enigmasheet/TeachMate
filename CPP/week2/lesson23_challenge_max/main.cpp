// Lesson 23 - Challenge: Largest number
// Goal: find the biggest value in an array with a loop.

#include <iostream>

int main()
{
    int numbers[6] = {12, 45, 7, 90, 33, 58};

    int largest = numbers[0];
    for (int i = 1; i < 6; i++)
    {
        if (numbers[i] > largest)
            largest = numbers[i];
    }

    std::cout << "Largest: " << largest << "\n";
    return 0;
}

// Try it:
//   1. Change the numbers and predict the answer first.
//   2. Also print the smallest number.
