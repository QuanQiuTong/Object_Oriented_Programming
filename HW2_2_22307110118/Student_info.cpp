#include "Student_info.h"
using std::istream;
using std::vector;
bool compare(const Student_info &x, const Student_info &y)
{
    if (x.homework.empty())
        return true; // Empty ones goes first.
    if (y.homework.empty())
        return false;
    return x.total > y.total;
}
istream &read(istream &is, Student_info &s)
{
    is >> s.name >> s.midterm >> s.final_grade;
    read_hw(is, s.homework);
    return is;
}
istream &read_hw(istream &is, vector<double> &hw)
{
    if (is)
    {
        hw.clear();
        for (double x; is >> x;)
            hw.push_back(x);
        is.clear();
    }
    return is;
}