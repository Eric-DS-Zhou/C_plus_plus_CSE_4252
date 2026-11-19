#include <iostream>
#include "Shapes.h"

using namespace std;

// Circle
Circle::Circle(double r)
{
    radius = r;
}

double Circle::area() const
{
    return 3.14159 * radius * radius;
}

void Circle::display() const
{
    cout << "Circle: " << radius
         << " | Area = " << area() << endl;
}

// Rectangle
Rectangle::Rectangle(double l, double h)
{
    length = l;
    height = h;
}

double Rectangle::area() const
{
    return length * height;
}

void Rectangle::display() const
{
    cout << "Rectangle: " << length << ", " << height
         << " | Area = " << area() << endl;
}

// Trapezoid
Trapezoid::Trapezoid(double l, double h, double s)
{
    length = l;
    height = h;
    side = s;
}

double Trapezoid::area() const
{
    return (length + side) * height / 2;
}

void Trapezoid::display() const
{
    cout << "Trapezoid: " << length << ", "
         << height << ", " << side
         << " | Area = " << area() << endl;
}
