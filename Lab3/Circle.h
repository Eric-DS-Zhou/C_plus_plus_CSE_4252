#ifndef CIRCLE_H
#define CIRCLE_H

/* Represents a circle in a two-dimensional coordinate system. */
class Circle
{
public:
    /* Constructors */
    Circle();
    Circle(int x, int y, double radius);
    Circle(const Circle &other);

    /* Setters */
    void setX(int x);
    void setY(int y);
    void setRadius(double radius);

    /* Getters */
    int getX() const;
    int getY() const;
    double getRadius() const;

    /* Circle operations */
    void translate(int horizShift, int vertShift);
    double getArea() const;
    void displayCircle() const;
    bool intersect(Circle c) const;
    bool operator==(Circle c) const;

    /* Combines two circles using the specified coordinate rules. */
    friend Circle operator+(const Circle &c1, const Circle &c2);

private:
    int x;
    int y;
    double radius;
};

#endif
