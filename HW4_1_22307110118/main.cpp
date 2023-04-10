#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"

using std::cin;				using std::setprecision;
using std::cout;			using std::sort;
using std::domain_error;   	using std::streamsize;
using std::endl;			using std::string;
using std::max;				using std::vector;

int main()
{
	vector<Student_info> students;
	string::size_type maxlen = 0;       // the length of the longest name

	// read and store all the students' data.
	// Invariant: 'students' contains all the student records read so far
	//			'maxlen' contains the length of the longest name in 'students'
	for(Student_info record; record.read(cin);) {
		// find length of longest name
		maxlen = max(maxlen, record.name().size());
		students.push_back(record);
	}

	// alphabetize the student records
	sort(students.begin(), students.end(), compare);

	// write the names and grades
	for (vector<Student_info>::size_type i = 0;
	     i != students.size(); ++i) {

		// write the name, padded on the right to 'maxlen+1' characters
		cout << students[i].name()
		     << string(maxlen + 1 - students[i].name().size(), ' ');

		// compute and write the grade
		if(students[i].valid()) {
			streamsize prec = cout.precision(3);
			cout << students[i].grade()
			     << setprecision(prec);
		} else {
			cout << "student has done no homework";
		}
		cout << endl;
	}
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

/*
Baker     67.2
Carpenter 82
Davis     75
Edwards   78.2
Fail1     58
Fail2     57
Franklin  66.6
Harris    92.4
Jones     77.2
Liu       student has done no homework  
Miller    student has done no homework  
Moo       100
Moore     79.4
Norman    72.8
Olson     82.8
Peerson   66.6
Russel    79.4
Smith     87.2
Thomas    95.6
Vaughn    87
Westerly  86.2
*/