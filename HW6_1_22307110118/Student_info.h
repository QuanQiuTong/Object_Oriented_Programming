#ifndef GUARD_Student_info
#define GUARD_Student_info

// 'Student_info.h' header file
#include <iostream>
#include <string>
#include "Vec.h"
#include <stdexcept>

class Student_info
{
public:
	Student_info() : midterm(0), final_(0) {}
	Student_info(std::istream &is) { read(is); }
	std::string name() const { return n; };
	bool valid() const { return !homework.empty(); }
	std::istream &read(std::istream &);
	double grade() const;
	std::string letter_grade() const;

private:
	std::string n;
	double midterm, final_; // "final" is a C++ keyword.
	Vec<double> homework;
	std::istream &read_hw(std::istream &, Vec<double> &);
};

bool compare(const Student_info &, const Student_info &);

#endif
