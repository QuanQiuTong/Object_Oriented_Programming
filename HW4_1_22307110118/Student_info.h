#ifndef GUARD_Student_info
#define GUARD_Student_info

// 'Student_info.h' header file
#include <iostream>
#include <string>
#include <vector>

class Student_info
{
public:
	Student_info();
	Student_info(std::istream &);
	std::string name() const { return n; };
	bool valid() const { return !homework.empty(); }
	std::istream &read(std::istream &);
	double grade() const;

private:
	std::string n;
	double midterm, final_; // "final" is a C++ keyword.
	std::vector<double> homework;
	std::istream &read_hw(std::istream &, std::vector<double> &);
};

bool compare(const Student_info &, const Student_info &);

#endif
