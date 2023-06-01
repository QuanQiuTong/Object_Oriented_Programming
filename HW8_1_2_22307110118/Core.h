#ifndef CORE_H
#define CORE_H

#include <iostream>
#include <string>
#include <vector>

#include "median.h"

class Core
{
    friend class Student_info;

public:
    Core() : midterm(0), _final(0) {}
    Core(std::istream &is) { read(is); }
    virtual ~Core() {}

    std::string name() const { return _name; }

    virtual std::istream &read(std::istream &in) { return read_hw(read_common(in), homework); }
    virtual double grade() const { return 0.2 * midterm + 0.4 * _final + 0.4 * median(homework); }

    bool operator<(const Core &rhs) const { return _name < rhs._name; }

protected:
    virtual Core *clone() const { return new Core(*this); }

    std::istream &read_common(std::istream &in) { return in >> _name >> midterm >> _final; }

    double midterm, _final;
    std::vector<double> homework;

    // read homework grades from an input stream into a 'vector<double>'
    std::istream &read_hw(std::istream &in, std::vector<double> &hw)
    {
        if (in)
        {
            // get rid of previous contents
            hw.clear();

            // read homework grades
            double x;
            while (in >> x)
                hw.push_back(x);

            // clear the stream so that input will work for the next student
            in.clear();
        }
        return in;
    }

private:
    std::string _name;
};
bool compare_grades(const Core &lhs, const Core &rhs)
{
    return lhs.grade() < rhs.grade();
}
#endif
