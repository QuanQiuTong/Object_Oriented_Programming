#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

#include <cmath>

struct Shape
{
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    bool operator<(const Shape &rhs) const { return area() < rhs.area(); }
};

class Triangle : public Shape
{
public:
    Triangle(std::istream &is) { is >> a >> b >> c; }
    Triangle(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}
    double area() const
    {
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
    double perimeter() const { return a + b + c; }

private:
    double a, b, c;
};

class Rectangle : public Shape
{
public:
    Rectangle(std::istream &is) { is >> a >> b; }
    double area() const { return a * b; }
    double perimeter() const { return (a + b) * 2; }

private:
    double a, b;
};

class Circle : public Shape
{
public:
    Circle(std::istream &is) { is >> r; }
    double area() const { return pi * r * r; }
    double perimeter() const { return 2 * pi * r; }

private:
    static const double pi;
    double r;
};
//const double Circle::pi = acos(-1);
bool comp_ptr(const Shape *p, const Shape *q) { return p->area() < q->area(); }
#endif
