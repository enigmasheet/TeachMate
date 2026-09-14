// Lesson 49 - Challenge: Safe number parsing
// Goal: convert text to a number without crashing.

#include <iostream>
#include <optional>
#include <stdexcept>
#include <string>

std::optional<int> toInt(const std::string &text)
{
    try
    {
        return std::stoi(text);
    }
    catch (const std::exception &)
    {
        return std::nullopt;
    }
}

int main()
{
    std::string inputs[] = {"42", "19", "hello", "7"};

    for (const std::string &text : inputs)
    {
        std::optional<int> value = toInt(text);
        if (value.has_value())
            std::cout << "'" << text << "' -> " << value.value() << "\n";
        else
            std::cout << "'" << text << "' is not a number\n";
    }

    return 0;
}

// Try it:
//   1. Add "3.14" to the list and see what std::stoi does with it.
//   2. Also reject negative numbers (return std::nullopt for them).
