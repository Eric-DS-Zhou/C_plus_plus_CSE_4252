#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

#include "Shape.h"

class Quadrilateral : public Shape
{
protected:
    double length;
    double height;

public:
    Quadrilateral() {
        length = 0;
        height = 0;
    }

    Quadrilateral(double l, double h) {
        length = l;
        height = h;
    }
};

#endif
