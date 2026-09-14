// Lesson 42 - Lambdas
// Goal: write a small function right where you use it.

#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> numbers = {4, 7, 10, 13, 16, 21};

    // A lambda is a function stored in a variable.
    auto isEven = [](int n)
    {
        return n % 2 == 0;
    };

    std::cout << "isEven(10) = " << isEven(10) << "\n";

    int evens = std::count_if(numbers.begin(), numbers.end(), isEven);
    std::cout << "Even numbers: " << evens << "\n";

    int limit = 12;
    int big = std::count_if(numbers.begin(), numbers.end(),
                            [limit](int n) { return n > limit; });
    std::cout << "Numbers over 12: " << big << "\n";

    return 0;
}

// Try it:
//   1. Write a lambda that tests whether a number is negative.
//   2. Count how many numbers are less than a value you choose.
