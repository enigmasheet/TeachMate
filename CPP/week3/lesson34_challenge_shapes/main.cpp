// Lesson 34 - Challenge: Shapes
// Goal: use inheritance and virtual methods to compute areas.

#include <iostream>

class Shape
{
public:
    virtual double area() const
    {
        return 0.0;
    }
};

class Rectangle : public Shape
{
public:
    double width;
    double height;

    Rectangle(double w, double h)
    {
        width = w;
        height = h;
    }

    double area() const override
    {
        return width * height;
    }
};

class Circle : public Shape
{
public:
    double radius;

    Circle(double r)
    {
        radius = r;
    }

    double area() const override
    {
        return 3.14159 * radius * radius;
    }
};

int main()
{
    Rectangle r(4, 5);
    Circle c(3);

    Shape &s1 = r; // a Shape reference can point at a Rectangle
    Shape &s2 = c; // ... or at a Circle

    std::cout << "Rectangle area: " << s1.area() << "\n";
    std::cout << "Circle area:    " << s2.area() << "\n";

    return 0;
}

// Try it:
//   1. Add a Triangle class with a base and height.
//   2. Print every shape's area by calling area() through the Shape reference.
