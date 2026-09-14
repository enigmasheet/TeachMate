// Lesson 18 - Reading a whole line
// Goal: read text that contains spaces.
//
// std::cin >> stops at the first space. std::getline reads the whole line.

#include <iostream>
#include <string>

int main()
{
    std::string fullName;

    std::cout << "Enter your full name: ";
    std::getline(std::cin, fullName);

    std::cout << "Hello, " << fullName << "!\n";
    std::cout << "Your name has " << fullName.size() << " characters.\n";

    return 0;
}

// Try it:
//   1. Print the name twice, separated by a comma.
//   2. Read a favourite sentence and print how long it is.
