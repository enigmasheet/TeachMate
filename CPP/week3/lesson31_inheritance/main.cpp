// Lesson 31 - Inheritance
// Goal: build a new class from an existing one.

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

    void eat()
    {
        std::cout << name << " is eating.\n";
    }
};

// Dog is an Animal and adds its own behaviour.
class Dog : public Animal
{
public:
    Dog(std::string n) : Animal(n) // pass the name up to Animal
    {
    }

    void bark()
    {
        std::cout << name << " says woof!\n";
    }
};

int main()
{
    Dog rex("Rex");
    rex.eat();  // comes from Animal
    rex.bark(); // comes from Dog

    return 0;
}

// Try it:
//   1. Add a class Cat with a meow() method.
//   2. Give Animal a sleep() method and call it on the dog.
