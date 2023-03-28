#include "Student_info.h"
#include "grade.h"
#include <list>
using std::list;
bool fgrade(const Student_info &s)
{
	return grade(s) < 60;
}
list<Student_info> extract_fails(list<Student_info> &s)
{
	list<Student_info> fail;
	for (list<Student_info>::iterator it = s.begin(); it != s.end();)
	{
		if (fgrade(*it))
		{
			fail.push_back(*it);
			it = s.erase(it);
		}
		else
			++it;
	}
	return fail;
}
