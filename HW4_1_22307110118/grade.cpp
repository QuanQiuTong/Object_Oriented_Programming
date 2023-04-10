#include <stdexcept>
#include <vector>
#include "grade.h"
#include "median.h"
#include "Student_info.h"

using std::domain_error;
using std::vector;

// compute a student's overall grade from midterm and final exam grades and homework grade
double grade(double midterm, double final_, double homework)
{
	return 0.2 * midterm + 0.4 * final_ + 0.4 * homework;
}

// compute a student's overall grade from midterm and final exam grades
// and vector of homework grades.
// this function does not copy its argument, because `median' does so for us.
double grade(double midterm, double final_, const vector<double> &hw)
{
	if (hw.size() == 0)
		throw domain_error("student has done no homework");
	return grade(midterm, final_, median(hw));
}
