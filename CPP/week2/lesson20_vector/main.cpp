// Lesson 20 - std::vector
// Goal: store a list that can grow, unlike a fixed-size array.

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> marks;

    marks.push_back(70);
    marks.push_back(85);
    marks.push_back(60);

    std::cout << "Size: " << marks.size() << "\n";

    // "for each m in marks" - a short way to visit every item.
    for (int m : marks)
    {
        std::cout << m << "\n";
    }

    return 0;
}

// Try it:
//   1. Add two more marks with extra push_back lines.
//   2. Print only the marks that are 80 or more.
