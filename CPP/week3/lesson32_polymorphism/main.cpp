// Lesson 32 - Polymorphism
// Goal: one call, different behaviour for different types.
//
// "virtual" lets a derived class replace a base-class method.

#include <iostream>
#include <string>

class Animal
{
public:
    std::string name;

    Animal(std::string n)
    {
        name = n;
    }

    virtual void speak()
    {
        std::cout << name << " makes a sound.\n";
    }
};

class Dog : public Animal
{
public:
    Dog(std::string n) : Animal(n) {}

    void speak() override
    {
        std::cout << name << " says woof!\n";
    }
};

class Cat : public Animal
{
public:
    Cat(std::string n) : Animal(n) {}

    void speak() override
    {
        std::cout << name << " says meow!\n";
    }
};

int main()
{
    Dog rex("Rex");
    Cat tom("Tom");

    // A base-class reference can point at any derived object.
    Animal &a = rex;
    a.speak();

    Animal &b = tom;
    b.speak();

    return 0;
}

// Try it:
//   1. Remove `virtual` and see which line is printed twice.
//   2. Add a Cow class with its own speak().
