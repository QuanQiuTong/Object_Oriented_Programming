#ifndef GRAD_H
#define GRAD_H

#include <iostream>
#include <algorithm>

#include "Core.h"
class Grad : public Core
{

public:
    Grad() : thesis(0) {}
    Grad(std::istream &is) { read(is); }
    Grad *clone() const { return new Grad(*this); }

    std::istream &read(std::istream &in)
    {
        read_common(in) >> thesis;
        return read_hw(in, homework);
    }
    double grade() const { return std::min(Core::grade(), thesis); }

private:
    double thesis;
};
#endif
