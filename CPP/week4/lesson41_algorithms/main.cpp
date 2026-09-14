// Lesson 41 - Algorithms
// Goal: use ready-made algorithms instead of writing loops by hand.

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main()
{
    std::vector<int> marks = {88, 79, 95, 60, 95};

    std::sort(marks.begin(), marks.end());

    std::cout << "Sorted: ";
    for (int m : marks)
        std::cout << m << " ";
    std::cout << "\n";

    std::cout << "Count of 79:  " << std::count(marks.begin(), marks.end(), 79) << "\n";
    std::cout << "Count of 95:  " << std::count(marks.begin(), marks.end(), 95) << "\n";
    std::cout << "Total:        " << std::accumulate(marks.begin(), marks.end(), 0) << "\n";

    return 0;
}

// Try it:
//   1. Find the largest value with std::max_element.
//   2. Sort the marks from largest to smallest using std::greater<int>().
