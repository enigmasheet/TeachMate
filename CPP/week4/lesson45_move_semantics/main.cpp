// Lesson 45 - Move semantics
// Goal: transfer data instead of making a copy.

#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main()
{
    std::string original = "a fairly long piece of text";

    // std::move lets the vector take the string's memory instead of copying it.
    std::vector<std::string> words;
    words.push_back(std::move(original));

    std::cout << "In the vector: " << words[0] << "\n";

    // After a move the original is empty (but safe to destroy).
    std::cout << "Original size now: " << original.size() << "\n";

    return 0;
}

// Try it:
//   1. Remove std::move and compare: the original keeps its text.
//   2. Moving matters most for big objects such as strings and vectors.
