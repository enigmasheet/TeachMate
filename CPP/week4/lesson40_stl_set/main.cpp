// Lesson 40 - std::set
// Goal: keep a collection of unique items, sorted automatically.

#include <iostream>
#include <set>
#include <string>

int main()
{
    std::set<std::string> names;

    names.insert("Sam");
    names.insert("Mia");
    names.insert("Sam"); // duplicate: ignored

    std::cout << "Number of names: " << names.size() << "\n";

    for (const std::string &n : names)
    {
        std::cout << n << "\n"; // printed in sorted order
    }

    std::cout << "Has Mia? " << names.count("Mia") << "\n"; // 1 = yes

    return 0;
}

// Try it:
//   1. Insert your own name and the same name twice.
//   2. Use count() to test for a name that is not present.
