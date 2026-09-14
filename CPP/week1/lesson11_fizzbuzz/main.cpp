// Lesson 11 - Challenge: FizzBuzz
// Goal: use % and if / else if inside a loop.
//
// For each number from 1 to 15:
//   - print "FizzBuzz" if it is divisible by both 3 and 5
//   - print "Fizz" if it is divisible by 3
//   - print "Buzz" if it is divisible by 5
//   - otherwise print the number

#include <iostream>

int main()
{
    for (int i = 1; i <= 15; i++)
    {
        if (i % 15 == 0)
            std::cout << "FizzBuzz\n";
        else if (i % 3 == 0)
            std::cout << "Fizz\n";
        else if (i % 5 == 0)
            std::cout << "Buzz\n";
        else
            std::cout << i << "\n";
    }
    return 0;
}

// Try it: change 15 to 30, and add a rule for multiples of 7.
