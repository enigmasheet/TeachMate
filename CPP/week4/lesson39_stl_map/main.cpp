// Lesson 39 - std::map
// Goal: store data as key -> value pairs.

#include <iostream>
#include <map>
#include <string>

int main()
{
    std::map<std::string, int> marks;

    marks["Sam"] = 88;
    marks["Mia"] = 95;
    marks["Ada"] = 79;

    std::cout << "Sam scored " << marks["Sam"] << "\n";
    std::cout << "Number of students: " << marks.size() << "\n";

    // A map keeps its keys in sorted order. A structured binding splits each
    // entry into its two parts: the key (name) and the value (mark).
    for (const auto &[name, mark] : marks)
    {
        std::cout << name << " -> " << mark << "\n";
    }

    std::cout << "Is Zoe in the map? " << marks.count("Zoe") << "\n"; // 0 = no

    return 0;
}

// Try it:
//   1. Add another student.
//   2. Print only students with a mark of 80 or more (use the mark binding).
