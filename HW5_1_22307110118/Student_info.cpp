// source file for 'Student_info'-related functions
#include "Student_info.h"
#include "grade.h"
#include "median.h"

using std::istream;
using std::vector;

istream &Student_info::read(istream &is)
{
	is >> n >> midterm >> final_;
	read_hw(is, homework);
	return is;
}

// compute a student's overall grade from midterm and final exam grades
// and vector of homework grades.
// this function does not copy its argument, because `median' does so for us.
double Student_info::grade() const
{
	if (homework.empty())
		throw std::domain_error("student has done no homework");
	return ::grade(midterm, final_, median(homework.begin(),homework.end()));
}

// read homework grades from an input stream into a 'vector<double>'
istream &Student_info::read_hw(istream &in, vector<double> &hw)
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

std::string Student_info::letter_grade()const{
	return ::letter_grade(grade());
}

bool compare(const Student_info &x, const Student_info &y)
{
	return x.name() < y.name();
}