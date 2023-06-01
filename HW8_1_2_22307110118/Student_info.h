#ifndef GUARD_STUDENT_INFO_H
#define GUARD_STUDENT_INFO_H

#include <iostream>

#include "Core.h"
#include "Grad.h"

class Student_info
{

public:
    Student_info() : cp(0) {}
    Student_info(std::istream &is) : cp(0) { read(is); }
    Student_info(const Student_info &s) { cp = s.cp ? s.cp->clone() : 0; }
    Student_info &operator=(const Student_info &s)
    {
        if (&s != this)
        {
            delete cp;
            cp = s.cp ? s.cp->clone() : 0;
        }
        return *this;
    }
    ~Student_info() { delete cp; }

    std ::istream &read(std ::istream &is)
    {
        delete cp;
        cp = 0; // 防止对同一地址删除两次而发生未定义行为。delete nullptr良定义。
        char ch;
        is >> ch;
        if (!bool(is))
            return is;
        if (ch == 'U')
            cp = new Core(is);
        else if (ch == 'G')
            cp = new Grad(is);
        return is;
    }
    std ::string name() const
    {
        if (cp)
            return cp->name();
        else
            throw std ::runtime_error("uninitialized student ");
    }
    double grade() const
    {
        if (cp)
            return cp->grade();
        else
            throw std ::runtime_error("uninitialized student ");
    }
    static bool compare(const Student_info &sl, const Student_info &s2) { return sl.name() < s2.name(); }

private:
    Core *cp;
};
#endif