#include "date.h"
#include <iostream>

using std::abs;
using std::cout;
using std::domain_error;
using std::endl;
using std::min;

static const int length[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

void Date::year_increase()
{
    d = min(d, length[leap(++y)][m]);
}
void Date::month_increase()
{
    if (++m > 12)
        m = 1, ++y;
    d = min(d, length[leap(y)][m]);
}
void Date::day_increase()
{
    // if (++d > length[leap(y)][m]) d = 1, month_increase();

    (++d > length[leap(y)][m]) && (d = 1, ++m > 12) && (m = 1, ++y);
}
static bool leap(int y){
    return y % 400 == 0 || (y % 4 == 0 && y % 100);
}
signed Date::check() const
{

    if (m < 1 || m > 12)
        return invalid_month;
    if (d < 1 || d > length[leap(y)][m])
        return invalid_day;
    return valid;
}


static int daysofyear(int year){//返回周年的天数 
    return year*365+year/4-year/100+year/400;
}
 
/* static int daysofdate(int year,int mon,int mday){
    return 
        mon<=2?
            //天数是周年的天数加上当年已过完的月份的天数加日 
            daysofyear(year-1)+(mon-1)*30+mon*7/12+mday-1
        :(
            //天数是虚年的天数减去当年未过完的月份的天数加日
            daysofyear(year)-(13-mon)*30-(14-mon)*7/12+mday-1
        );
}
static int daysofdate(Date t){
    // if(t.year()<0);
    return daysofdate(t.year(),t.month(),t.day());
} */

    static int DoD(Date t)
    {
        int yday = t.day()-1;
        for(int i=1;i<t.month();++i)
            yday+=length[leap(t.year())][i];
        //printf("? %d == %d\n",daysofyear(t.year()-1)+yday,daysofdate(t));
        return t.year()>0?
        daysofyear(t.year()-1)+yday:
        -(daysofyear(- t.year())+365+leap(t.year())-yday);
    }



int inteval(Date l, Date r)
{
    /* if (l.year() < r.year() || l.year() == r.year() &&
                                   (l.month() < r.month() || (l.month() == r.month() &&
                                                              l.day() < r.day())))
    {
        Date t(l);
        l = r, r = t;
    } */
    return abs(DoD(l)-DoD(r));
}

#if 0
#include<cstdio>
using namespace std;
inline ostream& operator <<(ostream& os, Date d){
    //printf("date: %d-%d-%d == %d\n",d.year(),d.month(),d.day(),daysofdate(d));
    return os<<d.year()<<'-'<<d.month()<<'-'<<d.day()<<" == "<<daysofdate(d);
}
int main(){
    Date d(4,2,29),dd(0,12,31);
    
    // cout<<"Common Era: "<<Date(1,1,1)<<endl; //1-1-1 == 0

    cout<<d<<endl<<dd<<endl<<inteval(d,dd)<<endl;
    DoD(d),DoD(dd);

    //Passed when positive! 
    for(int i=-396;i<=40001;++i)
    for(int j=1;j<=12;++j){
        Date d(i,j,28);
        if(daysofdate(d)!=DoD(d))cout<<d<<" != "<<DoD(d)<<endl;
        
    } 
    cout<<DoD(Date(0,1,1))<<endl;
}
#endif

//留待生成对拍器
#if 0
#include<cstdlib>
int main(){
    srand(time(NULL));
    #define randint (rand()<<15|rand())
    Date dd(1,1,1);
    for(int _=1e4;_--;){
        int y=randint,m=randint%12+1;
        if(rand()&1)y=-y;
        Date d(y,m,randint%length[leap(y)][m]+1);
        cout<<inteval(d,dd)<<endl;
        dd=d;
    }
}
#endif
