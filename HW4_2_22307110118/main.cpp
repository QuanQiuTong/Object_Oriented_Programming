#include <iostream>
#include "date.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    cout << "请输入两个日期(年月日，以空格分隔)：" << endl;
    Date d1(cin);
    switch (d1.check())
    {
    case Date::invalid_month:
        cout << "invalid month" << endl;
        return 1;
    case Date::invalid_day:
        cout << "invalid day" << endl;
        return 1;
    default:
        break;
    }
    Date d2(cin);
    cout << "日期一：", d1.print(), cout << endl;
    cout << "日期二：", d2.print(), cout << endl;
    cout << "两个日期相隔天数为：" << inteval(d1, d2) << endl;
    cout << "给日期一增加一天为：", d1.day_increase(), d1.print(), cout << endl;
    cout << "给日期一增加一月为：", d1.month_increase(), d1.print(), cout << endl;
    cout << "给日期一增加一年为：", d1.year_increase(), d1.print(), cout << endl;
    return 0;
}