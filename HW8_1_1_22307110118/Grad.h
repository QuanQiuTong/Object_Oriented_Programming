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

    std::istream &read(std::istream &in) { return read_hw(read_common(in) >> thesis, homework); }
    double grade() const { return std::min(Core::grade(), thesis); }

private:
    double thesis;
};
#endif
