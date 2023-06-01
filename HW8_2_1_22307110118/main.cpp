#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>

#include "shape.h"
const double Circle::pi = acos(-1);

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::sort;
using std::string;
using std::vector;

int main()
{
    ifstream fin("shapes");
    vector<Shape *> shapes;
    for (char ch; fin >> ch;)
    {
        Shape *p;
        if (ch == 'T')
        {
            double edge[3];
            fin >> edge[0] >> edge[1] >> edge[2];
            sort(edge, edge + sizeof(edge) / sizeof(*edge));
            if (edge[0] + edge[1] <= edge[2])
            {
                cout << edge[0] << ", " << edge[1] << ", " << edge[2] << " can't make a triangle." << endl;
                continue;
            }
            p = new Triangle(edge[0], edge[1], edge[2]);
        }
        else if (ch == 'R')
            p = new Rectangle(fin);
        else /*if (ch == 'C')*/
            p = new Circle(fin);
        shapes.push_back(p);
    }
    fin.close();

    sort(shapes.begin(), shapes.end(), comp_ptr);

    ofstream fout("result.csv");
    cout << "\nArea    Perimeter\n";
    fout << "Area,Perimeter\n";
    cout << std::setprecision(3);
    fout.precision(3);
    for (vector<Shape *>::size_type i = 0; i != shapes.size(); ++i)
    {
        const Shape *p = shapes[i];
        cout << std::setiosflags(std::ios::left) << std::setw(8) << p->area() << p->perimeter() << endl;
        fout << p->area() << ',' << p->perimeter() << '\n';
    }
    fout.close();
    return 0;
}