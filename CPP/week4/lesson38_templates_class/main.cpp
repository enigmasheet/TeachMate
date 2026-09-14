// Lesson 38 - Class templates
// Goal: make a class that can hold any type.

#include <iostream>
#include <string>

template <typename T>
class Box
{
public:
    T value;

    Box(T v) : value(v) {}

    T get() const
    {
        return value;
    }

    void show() const
    {
        std::cout << "Box holds: " << value << "\n";
    }
};

int main()
{
    Box<int> numbers(42);
    Box<std::string> words("hello");
    Box<double> price(9.99);

    numbers.show();
    words.show();
    price.show();

    std::cout << "Box<int> value: " << numbers.get() << "\n";
    return 0;
}

// Try it:
//   1. Make a Box<bool> containing true.
//   2. Add a method `void set(T v)` that changes the value.
