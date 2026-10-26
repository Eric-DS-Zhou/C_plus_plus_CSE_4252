#include <iostream>
#include "Circle.h"

using namespace std;

/* Exercises every constructor and method of the Circle class. */
int main()
{
    cout << boolalpha;

    /* Test constructors and display. */
    Circle a;
    Circle b(-3, 4, 2.0);
    Circle copy(b);
    cout << "Default constructor: ";
    a.displayCircle();
    cout << "Parameterized constructor: ";
    b.displayCircle();
    cout << "Copy constructor: ";
    copy.displayCircle();

    /* Test getters and setters, including an invalid radius. */
    cout << "Getters for b: x=" << b.getX() << ", y=" << b.getY()
         << ", radius=" << b.getRadius() << endl;
    copy.setX(2);
    copy.setY(-6);
    copy.setRadius(3.5);
    cout << "After setters: ";
    copy.displayCircle();
    copy.setRadius(-2.0);
    cout << "After invalid radius: ";
    copy.displayCircle();

    /* Test translation and area. */
    b.translate(5, -2);
    cout << "After translation: ";
    b.displayCircle();
    cout << "Area of b: " << b.getArea() << endl;

    /* Test intersect: overlap, separation, tangency, and containment. */
    Circle overlapping(3, 2, 2.0);
    Circle separate(20, 20, 1.0);
    Circle touching(9, 2, 5.0);
    Circle contained(2, 2, 1.0);
    cout << "Overlapping circles intersect: " << b.intersect(overlapping) << endl;
    cout << "Separate circles intersect: " << b.intersect(separate) << endl;
    cout << "Touching circles intersect: " << b.intersect(touching) << endl;
    cout << "Contained circle intersects: " << a.intersect(contained) << endl;

    /* Test equality and addition operators. */
    Circle equalToB(b);
    cout << "b == equalToB: " << (b == equalToB) << endl;
    cout << "b == a: " << (b == a) << endl;
    Circle combined = b + copy;
    cout << "b + copy: ";
    combined.displayCircle();

    return 0;
}
