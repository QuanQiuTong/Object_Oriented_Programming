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

const char *letter_grade(double grade)
{
	if (grade >= 90.0)
		return "A";
	if (grade >= 85.0)
		return "A-";
	if (grade >= 82.0)
		return "B+";
	if (grade >= 78.0)
		return "B";
	if (grade >= 75.0)
		return "B-";
	if (grade >= 71.0)
		return "C+";
	if (grade >= 66.0)
		return "C";
	if (grade >= 62.0)
		return "C-";
	if (grade >= 60.0)
		return "D";
	return "F";
}