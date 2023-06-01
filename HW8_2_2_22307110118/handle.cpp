#include <algorithm>

#include "handle.h"

std::istream &Handle::read(std::istream &in)
{
    delete p;
    char ch;
    in >> ch;
    if (ch == 'T')
    {
        double edge[3];
        in >> edge[0] >> edge[1] >> edge[2];
        std::sort(edge, edge + sizeof(edge) / sizeof(*edge));
        if (edge[0] + edge[1] <= edge[2])
            std::cout << edge[0] << ", " << edge[1] << ", " << edge[2] << " can't make a triangle." << std::endl, p = 0;
        else
            p = new Triangle(edge[0], edge[1], edge[2]);
    }
    else if (ch == 'R')
        p = new Rectangle(in);
    else if (ch == 'C')
        p = new Circle(in);
    return in;
}
double Handle::area() const
{
    if (p)
        return p->area();
    else
        throw std::runtime_error("uninitialized shape");
}
double Handle::perimeter() const
{
    if (p)
        return p->perimeter();
    else
        throw std::runtime_error("uninitialized shape");
}
bool compare(const Handle &lhs, const Handle &rhs)
{
    return lhs.area() < rhs.area();
}