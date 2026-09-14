// Lesson 24 - Challenge: Reverse a word
// Goal: read text and print it backwards.

#include <iostream>
#include <string>

int main()
{
    std::string word;
    std::cout << "Enter a word: ";
    std::cin >> word;

    int n = word.size();

    std::cout << "Reversed: ";
    for (int i = n - 1; i >= 0; i--)
    {
        std::cout << word[i];
    }
    std::cout << "\n";

    return 0;
}

// Try it:
//   1. Test with "level". It reads the same both ways - that is a palindrome.
//   2. Try a word with a space in it. What happens?
