#ifndef STUDENT_INFO
#define STUDENT_INFO
#include <iostream>
#include <vector>
#include <string>
struct Student_info
{
    std::string name;
    double midterm, final_grade, total; //"final" is a C++ keyword.
    std::vector<double> homework;
};
bool compare(const Student_info &, const Student_info &);
std::istream &read(std::istream &, Student_info &);
std::istream &read_hw(std::istream &, std::vector<double> &);
#endif
