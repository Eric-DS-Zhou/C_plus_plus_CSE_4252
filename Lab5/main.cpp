#include "Shapes.h"

void print(const Shape &s)
{
    s.display();
}

int main()
{
    Circle c(10);
    Rectangle r(3, 4);
    // Quadrilateral q(2, 4);

    Trapezoid trap(3, 4, 5);

    print(c);
    print(r);
    print(trap);

    return 0;
}
