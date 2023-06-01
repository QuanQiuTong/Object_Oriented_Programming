#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <ios>
#include <iomanip>
#include <stdexcept>

#include "Core.h"
#include "Grad.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::max;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

int main()
{
    vector<Core *> students;

    string ::size_type maxlen = 0;
    for (char ch; cin >> ch;)
    {
        Core *record;
        if (ch == 'U')
            record = new Core;
        else /* if (ch == 'G')*/
            record = new Grad;
        record->read(cin);
        maxlen = max(maxlen, record->name().size());
        students.push_back(record);
    }

    sort(students.begin(), students.end(), compare_ptr);

    for (vector<Core *>::size_type i = 0; i < students.size(); ++i)
    {
        const Core *it = students[i];
        cout << it->name() << string(maxlen + 1 - it->name().size(), ' ');
        try
        {
            double final_grade = it->grade();
            streamsize prec = cout.precision(3);
            cout << final_grade << setprecision(prec) << endl;
        }
        catch (domain_error e)
        {
            cout << e.what() << endl;
        }
        delete it;
    }
    return 0;
}