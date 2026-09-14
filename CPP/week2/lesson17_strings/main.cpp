// Lesson 17 - Working with text
// Goal: join, measure and inspect std::string values.

#include <iostream>
#include <string>

int main()
{
    std::string first = "Ada";
    std::string last = "Lovelace";
    std::string full = first + " " + last;

    std::cout << "Full name:    " << full << "\n";
    std::cout << "Length:       " << full.size() << "\n";
    std::cout << "First letter: " << full[0] << "\n";
    std::cout << "Last letter:  " << full[full.size() - 1] << "\n";

    return 0;
}

// Try it:
//   1. Use your own first and last name.
//   2. Make a greeting by joining "Hello, " with the full name.
