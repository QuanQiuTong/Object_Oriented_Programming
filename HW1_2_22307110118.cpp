#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
    int length, width, height;

    cout << "Enter the side length of a square: ";
    cin >> length;
    for (int i = 0; i != length; ++i)
    {
        for (int j = 0; j != length - 1; ++j)
            cout << "* ";
        cout << "*"; // At the end of a line, there should not be a blank.
        cout << endl;
    }

    cout << "Enter the length and width of a rectangle: ";
    cin >> length >> width;
    for (int i = 0; i != width; ++i)
    {
        for (int j = 0; j != length - 1; ++j)
            cout << "* ";
        cout << "*"; // No blank at the end.
        cout << endl;
    }

    cout << "Enter the base length of an isosceles triangle(odd number): ";
    cin >> length;
    height = (length + 1) / 2;
    for (int i = 0; i != height; ++i)
    {
        for (int j = 0; j != height + i; ++j)
        {
            if (i + j >= height - 1)
            {
                if (j != height + i)
                    cout << "* ";
                else
                    cout << "*"; // No blank at the end.
            }
            else
                cout << "  ";
        }
        cout << endl;
    }
    return 0;
}