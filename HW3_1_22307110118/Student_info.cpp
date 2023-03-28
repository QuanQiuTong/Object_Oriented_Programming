#include "Student_info.h"
using std::istream;
using std::vector;
bool compare(const Student_info &x, const Student_info &y)
{
    if (/*x.homework.empty() && y.homework.empty() ||*/ x.total == y.total)
        return x.name < y.name;
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
