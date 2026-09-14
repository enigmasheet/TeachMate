// Lesson 43 - Filtering and transforming with algorithms
// Goal: build a new list from an old one with std::copy_if and std::transform.

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main()
{
    std::vector<int> numbers = {5, 8, 12, 3, 20, 7};

    // Keep only the numbers greater than 6 ("filter").
    std::vector<int> big;
    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(big),
                 [](int n) { return n > 6; });

    std::cout << "Greater than 6: ";
    for (int n : big)
        std::cout << n << " ";
    std::cout << "\n";

    // Make a new list where every value is doubled ("transform" / "map").
    std::vector<int> doubled;
    std::transform(big.begin(), big.end(), std::back_inserter(doubled),
                   [](int n) { return n * 2; });

    std::cout << "Doubled: ";
    for (int n : doubled)
        std::cout << n << " ";
    std::cout << "\n";

    return 0;
}

// Try it:
//   1. Keep only the even numbers (n % 2 == 0).
//   2. Transform the numbers into their squares.
//
// These are the same ideas other languages call "filter" and "map".
