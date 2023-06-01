#ifndef HANDLE_H
#define HANDLE_H

#include <iostream>

#include "shape.h"
class Handle
{
private:
    Shape *p;

public:
    std::istream &read(std::istream &);
    Handle() { p = 0; }
    Handle(const Handle &other) { p = other.p ? other.p->clone() : 0; }
    Handle &operator=(const Handle &other)
    {
        if (&other != this)
        {
            delete p;
            p = other.p ? other.p->clone() : 0;
        }
        return *this;
    }
    ~Handle() { delete p; }
    bool valid() const { return p; }
    double area() const;
    double perimeter() const;
};
bool compare(const Handle &, const Handle &);
#endif
