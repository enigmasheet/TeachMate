// Lesson 09f - Challenge: Sum until zero
// Goal: read numbers until the user types 0, then print the count and sum.
//
// This brings together several ideas from lessons 09–09e:
//   - a `while (true)` + `break` loop
//   - an accumulator (`sum`) and a counter (`count`)
//   - `if` / `else` inside the loop

#include <iostream>

int main()
{
    int sum = 0;
    int count = 0;
    int n = 0;

    std::cout << "Enter numbers (0 to finish):\n";
    while (true)
    {
        std::cin >> n;

        if (n == 0)
            break;

        sum = sum + n;
        count = count + 1;
    }

    if (count == 0)
        std::cout << "No numbers entered.\n";
    else
    {
        std::cout << "Count: " << count << "\n";
        std::cout << "Sum:   " << sum << "\n";
        std::cout << "Mean:  " << sum / count << "\n";
    }

    return 0;
}

// Try it:
//   1. Also keep track of the largest number entered and print it.
//   2. Change 0 to -1 as the sentinel value.
//   3. Challenge: lesson09g builds a picture with nested loops.
