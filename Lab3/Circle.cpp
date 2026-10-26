#include <iostream>
#include <cmath>
#include "Circle.h"

using namespace std;

/* Creates a circle centered at (0, 0) with radius 5. */
Circle::Circle()
{
    x = 0;
    y = 0;
    radius = 5.0;
}

/* Creates a circle with the provided position and radius. */
Circle::Circle(int x, int y, double radius)
{
    this->x = x;
    this->y = y;
    setRadius(radius);
}

/* Copies the attributes of another circle. */
Circle::Circle(const Circle &other)
{
    x = other.x;
    y = other.y;
    radius = other.radius;
}

/* Changes the horizontal coordinate. */
void Circle::setX(int x)
{
    this->x = x;
}

/* Changes the vertical coordinate. */
void Circle::setY(int y)
{
    this->y = y;
}

/* Keeps the radius positive; invalid values are replaced by 5. */
void Circle::setRadius(double radius)
{
    if (radius > 0.0) {
        this->radius = radius;
    } else {
        this->radius = 5.0;
    }
}

/* Returns the horizontal coordinate. */
int Circle::getX() const
{
    return x;
}

/* Returns the vertical coordinate. */
int Circle::getY() const
{
    return y;
}

/* Returns the radius. */
double Circle::getRadius() const
{
    return radius;
}

/* Moves the center by the given horizontal and vertical shifts. */
void Circle::translate(int horizShift, int vertShift)
{
    x += horizShift;
    y += vertShift;
}

/* Calculates the circle's area. */
double Circle::getArea() const
{
    const double PI = 3.141592653589793;
    return PI * radius * radius;
}

/* Prints the circle's radius and center in the requested format. */
void Circle::displayCircle() const
{
    cout << "Radius: " << radius;

    if (radius == (int)radius)
    {
        cout << ".0";
    }

    cout << " at point x = " << x
         << ", y = " << y << endl;
}

/* Returns true when the two circular regions overlap or touch. */
bool Circle::intersect(Circle c) const
{
    double dx = x - c.x;
    double dy = y - c.y;
    double sumRadii = radius + c.radius;
    return dx * dx + dy * dy <= sumRadii * sumRadii;
}

/* Returns true when both circles have identical attributes. */
bool Circle::operator==(Circle c) const
{
    return x == c.x && y == c.y && radius == c.radius;
}

/* Adds radii and selects the signed coordinate of greater magnitude. */
Circle operator+(const Circle &c1, const Circle &c2)
{
    int newX;
    int newY;
    if (std::abs(c1.x) >= std::abs(c2.x)) {
        newX = c1.x;
    } else {
        newX = c2.x;
    }

    if (std::abs(c1.y) >= std::abs(c2.y)) {
        newY = c1.y;
    } else {
        newY = c2.y;
    }

    return Circle(newX, newY, c1.radius + c2.radius);
}
