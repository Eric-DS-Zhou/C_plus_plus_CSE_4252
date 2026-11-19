#ifndef SHAPES_H
#define SHAPES_H

#include "Shape.h"
#include "Quadrilateral.h"

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r);
    double area() const override;
    void display() const override;
};

class Rectangle : public Quadrilateral
{
public:
    Rectangle(double l, double h);
    double area() const override;
    void display() const override;
};

class Trapezoid : public Quadrilateral
{
private:
    double side;

public:
    Trapezoid(double l, double h, double s);
    double area() const override;
    void display() const override;
};

#endif
