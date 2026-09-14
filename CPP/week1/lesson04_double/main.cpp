// Lesson 04 - Decimal numbers
// Goal: store numbers that have a decimal point.

#include <iostream>

int main()
{
    double price = 12.50;
    double pocketMoney = 50.00;
    double change = pocketMoney - price;

    std::cout << "Price: " << price << "\n";
    std::cout << "You have: " << pocketMoney << "\n";
    std::cout << "Change: " << change << "\n";
    return 0;
}

// Try it:
//   1. Change the prices.
//   2. Print the change after buying two items.
