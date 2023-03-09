#include <iostream>
using std::cin;
using std::cout;
using std::endl;
bool isLeap(int year)
{
    return year % 400 == 0 || (year % 4 == 0 && year % 100);
}
int main()
{
    int year, month, day,
        length[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

    cout << "Enter the baby's birthday(year month day): ";
    cin >> year >> month >> day;
    for (int i = 100; i;) // i means remaining days to be added.
    {
        int len = length[isLeap(year)][month];
        if (i > len - day)// i is enough to make it 1st of next month.
        {
            i -= len - day + 1;
            day = 1;
            ++month;
        }
        else
        {
            day = i;
            i = 0;
        }
        if (month == 13)
        {
            month = 1;
            ++year;
        }
    }
    cout << "The baby's 100-day date is: " << year << " " << month << " " << day;
    return 0;
}