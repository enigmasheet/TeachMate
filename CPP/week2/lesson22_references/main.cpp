// Lesson 22 - Passing by reference
// Goal: let a function change the caller's variable.
//
// The & means "work on the caller's variable, not on a copy".

#include <iostream>

void addOne(int &value)
{
    value = value + 1;
}

// Without & the function gets its own copy, so the caller is unchanged.
void addOneCopy(int value)
{
    value = value + 1;
    std::cout << "  (the copy is now " << value << ")\n";
}

int main()
{
    int a = 10;
    addOne(a);
    std::cout << "After addOne:     " << a << "\n"; // 11

    int b = 10;
    addOneCopy(b);
    std::cout << "After addOneCopy: " << b << "\n"; // still 10

    return 0;
}

// Try it:
//   1. Write `void doubleIt(int &x)` that doubles the value.
//   2. Write a function that swaps two numbers using references.
