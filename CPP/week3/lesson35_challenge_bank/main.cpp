// Lesson 35 - Challenge: A bank account
// Goal: use a class with private data and methods.

#include <iostream>

class Account
{
private:
    double balance;

public:
    Account(double opening)
    {
        balance = opening;
    }

    void deposit(double amount)
    {
        if (amount > 0)
            balance = balance + amount;
    }

    bool withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance = balance - amount;
            return true; // success
        }
        return false; // refused
    }

    double getBalance() const
    {
        return balance;
    }
};

int main()
{
    Account acc(100.0);
    acc.deposit(50.0);
    acc.withdraw(30.0);

    std::cout << "Balance: " << acc.getBalance() << "\n";

    if (!acc.withdraw(1000.0))
        std::cout << "Withdrawal refused.\n";

    return 0;
}

// Try it:
//   1. Refuse any single deposit larger than 1000.
//   2. Print a message on each successful deposit.
