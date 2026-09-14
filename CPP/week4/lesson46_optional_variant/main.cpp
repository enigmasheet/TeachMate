// Lesson 46 - std::optional and std::variant
// Goal: express "maybe a value" and "one of several types".

#include <iostream>
#include <optional>
#include <string>
#include <variant>

// Returns no value when the name is not found.
std::optional<int> findMark(const std::string &name)
{
    if (name == "Sam")
        return 88;
    if (name == "Mia")
        return 95;
    return std::nullopt; // nothing
}

int main()
{
    std::optional<int> a = findMark("Sam");
    if (a.has_value())
        std::cout << "Sam: " << a.value() << "\n";

    std::optional<int> b = findMark("Zoe");
    std::cout << "Zoe found? " << b.has_value() << "\n";
    std::cout << "Zoe mark or 0: " << b.value_or(0) << "\n";

    // A variant holds exactly one of a fixed set of types.
    std::variant<int, std::string> value;
    value = 42;
    std::cout << "Variant holds: " << std::get<int>(value) << "\n";
    value = std::string("now text");
    std::cout << "Variant holds: " << std::get<std::string>(value) << "\n";

    return 0;
}

// Try it:
//   1. Use `if (a)` instead of `a.has_value()`.
//   2. Add a call to findMark("Ada") and print its value_or(-1).
