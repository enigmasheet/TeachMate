// Lesson 48 - Challenge: Word frequency
// Goal: count how often each word appears using a std::map.

#include <iostream>
#include <map>
#include <sstream>
#include <string>

int main()
{
    std::string line;
    std::cout << "Type a sentence: ";
    std::getline(std::cin, line);

    std::map<std::string, int> counts;

    std::istringstream stream(line);
    std::string token;
    while (stream >> token)
    {
        counts[token] = counts[token] + 1;
    }

    // Structured binding: each entry becomes (word, count).
    for (const auto &[word, count] : counts)
    {
        std::cout << word << ": " << count << "\n";
    }

    return 0;
}

// Try it:
//   1. Ignore the word "the" (skip it with an if).
//   2. Print the total number of words as well.
