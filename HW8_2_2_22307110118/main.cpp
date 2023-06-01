#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>

#include "handle.h"

void readinfo(std::ifstream &i, std::vector<Handle> &);
void cal_output(const std::vector<Handle> &);

int main()
{
    std::vector<Handle> shapes;
    std::ifstream infile("shapes");
    readinfo(infile, shapes);
    std::sort(shapes.begin(), shapes.end(), compare);
    cal_output(shapes);
    return 0;
}

void readinfo(std::ifstream &in, std::vector<Handle> &v)
{
    for (Handle h; h.read(in); /*std::cout<<"* "<<h.p<<std::endl*/)
        if (h.valid())
            v.push_back(h);
    in.close();
}

void cal_output(const std::vector<Handle> &v)
{
    using namespace std;
    ofstream fout("result.csv");
    cout << "\nArea    Perimeter\n";
    fout << "Area,Perimeter\n";
    cout << std::setprecision(3);
    fout.precision(3);
    for (vector<Handle>::const_iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << setiosflags(ios::left) << setw(8) << it->area() << it->perimeter() << endl;
        fout << it->area() << ',' << it->perimeter() << '\n';
    }
    fout.close();
}