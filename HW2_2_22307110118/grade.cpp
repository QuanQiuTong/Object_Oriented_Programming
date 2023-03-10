#include <stdexcept>
#include "median.h"
#include "Student_info.h"
#include "grade.h"
using std::domain_error;
using std::vector;
inline double grade(double mid, double fin, double hw)
{
    return 0.2 * mid + 0.4 * fin + 0.4 * hw;
}
double grade(double mid, double fin, const vector<double> &hw)
{
    if (hw.empty())
        throw domain_error("student has done no homework");
    return grade(mid, fin, median(hw));
}
double grade(const Student_info &s)
{
    return grade(s.midterm, s.final_grade, s.homework);
}
