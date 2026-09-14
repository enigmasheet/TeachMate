// Lesson 37 - Function templates
// Goal: write one function that works with many types.

#include <iostream>
#include <string>

// T stands for "some type". The compiler picks it from the arguments.
template <typename T>
T bigger(T a, T b)
{
    if (a > b)
        return a;
    return b;
}

int main()
{
    std::cout << "bigger(3, 7)     = " << bigger(3, 7) << "\n";
    std::cout << "bigger(9, 2)     = " << bigger(9, 2) << "\n";
    std::cout << "bigger(2.5, 1.5) = " << bigger(2.5, 1.5) << "\n";

    std::cout << "bigger(\"abc\", \"xyz\") = "
              << bigger(std::string("abc"), std::string("xyz")) << "\n";

    return 0;
}

// Try it:
//   1. Call bigger with two std::string values directly.
//   2. Write `template <typename T> T smaller(T a, T b)`.
