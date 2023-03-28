#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <list>
#include "grade.h"
#include "Student_info.h"
using namespace std; // 实在太多标识符了，求放过
#define space string(maxlen + 1 - i.name.size(), ' ')
extern list<Student_info> extract_fails(list<Student_info> &s); // 没有对应的头文件，只能这么做了
int main()
{
	list<Student_info> students, no_hw;
	string::size_type maxlen = 0;
	for (Student_info record; read(cin, record);)
	{
		maxlen = max(maxlen, record.name.size());
		try
		{
			record.total = grade(record);
			students.push_back(record);
		}
		catch (const domain_error &e)
		{
			no_hw.push_back(record);
		}
	}

	for (auto &&i : no_hw)
		cout << i.name << space << "student has done no homework" << endl;

	list<Student_info> fail = extract_fails(students);

	streamsize prec = cout.precision(3); // 以下并不会抛出错误，所以这么写
	students.sort(compare);
	cout << "\nPassing students:\n";
	for (auto &&i : students)
		cout << i.name << space << i.total << endl;

	fail.sort(compare);
	cout << "\nFailing students:\n";
	for (auto &&i : fail)
		cout << i.name << space << i.total << endl;
	cout.precision(prec);
	return 0;
}
/*
Moo 100 100 100 100 100 100 100 100
Moore 75 85 77 59 0 85 75 89
Norman 57 78 73 66 78 70 88 89
Olson 89 86 70 90 55 73 80 84
Peerson 47 70 82 73 50 87 73 71

Russel 72 87 88 54 55 82 69 87
Thomas 90 96 99 99 100 81 97 97
Vaughn 81 97 99 67 40 90 70 96
Westerly 43 98 96 79 100 82 97 96
Miller 75 62

Baker 67 72 73 40 0 78 55 70
Davis 77 70 82 65 70 77 83 81
Edwards 77 72 73 80 90 93 75 90
Franklin 47 70 82 73 50 87 73 71

Jones 77 82 83 50 10 88 65 80
Harris 97 90 92 95 100 87 93 91
Smith 87 92 93 60 0 98 75 90
Carpenter 47 90 92 73 100 87 93 91

Fail1 45 55 65 80 90 70 65 60
Fail2 55 55 65 50 55 60 65 60
Liu 80 90

*/