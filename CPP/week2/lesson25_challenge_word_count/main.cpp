// Lesson 25 - Challenge: Count characters and spaces
// Goal: read a full line and inspect each character.

#include <iostream>
#include <string>

int main()
{
    std::string line;
    std::cout << "Type a sentence: ";
    std::getline(std::cin, line);

    int letters = 0;
    int spaces = 0;
    int n = line.size();

    for (int i = 0; i < n; i++)
    {
        if (line[i] == ' ')
            spaces = spaces + 1;
        else
            letters = letters + 1;
    }

    std::cout << "Characters (not spaces): " << letters << "\n";
    std::cout << "Spaces: " << spaces << "\n";
    return 0;
}

// Try it:
//   1. Count the vowels (a, e, i, o, u) as well.
//   2. Print the sentence in upper case? (Hint: it is easier in Week 3.)
