// Lesson 30 - Operator overloading
// Goal: make an operator such as + work with your own type.

#include <iostream>

class Point
{
public:
    int x;
    int y;

    Point(int xValue, int yValue)
    {
        x = xValue;
        y = yValue;
    }

    // Called when we write `a + b`.
    Point operator+(const Point &other) const
    {
        return Point(x + other.x, y + other.y);
    }
};

int main()
{
    Point a(1, 2);
    Point b(3, 4);
    Point c = a + b;

    std::cout << "c = (" << c.x << ", " << c.y << ")\n";
    return 0;
}

// Try it:
//   1. Overload operator- to subtract two points.
//   2. Add three points together: a + b + a.
