#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"
int main()
{
	using namespace std;
	vector<Student_info> students;
	string::size_type maxlen = 0;
	for (Student_info record; read(cin, record);)
	{
		maxlen = max(maxlen, record.name.size());
		if (!record.homework.empty())
			record.total = grade(record);
		students.push_back(record);
	}
	stable_sort(students.begin(), students.end(), compare);
	for (auto &&i : students)
	{
		cout << i.name << string(maxlen + 1 - i.name.size(), ' ');
		try
		{
			streamsize prec = cout.precision();
			cout << setprecision(3) << grade(i) << setprecision(prec);
		}
		catch (domain_error e)
		{
			cout << e.what();
		}
		cout << endl;
	}
	return 0;
}
