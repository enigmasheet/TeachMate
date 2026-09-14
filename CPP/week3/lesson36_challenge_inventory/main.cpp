// Lesson 36 - Challenge: Inventory
// Goal: combine a class with a std::vector.

#include <iostream>
#include <string>
#include <vector>

class Item
{
public:
    std::string name;
    int quantity;

    Item(std::string n, int q)
    {
        name = n;
        quantity = q;
    }
};

int main()
{
    std::vector<Item> items;
    items.push_back(Item("Pens", 12));
    items.push_back(Item("Books", 3));
    items.push_back(Item("Bags", 7));

    int total = 0;
    for (const Item &it : items)
    {
        std::cout << it.name << ": " << it.quantity << "\n";
        total = total + it.quantity;
    }

    std::cout << "Total items: " << total << "\n";
    return 0;
}

// Try it:
//   1. Print only the items whose quantity is below 5.
//   2. Add a method `bool isLow() const` to Item that returns quantity < 5.
