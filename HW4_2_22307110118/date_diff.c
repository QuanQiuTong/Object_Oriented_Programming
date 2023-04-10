#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <math.h>

#include <time.h>

int get_days(const char *from, const char *to);

time_t convert(int year, int month, int day);

int main()

{

    const char *from = "2013-3-15";

    const char *to = "2015-8-14";

    int days = get_days(from, to);

    printf("From:%s\nTo:%s\n", from, to);

    printf("%d\n", days);

    return 0;
}

time_t convert(int year, int month, int day)

{

    struct tm info = {0};

    info.tm_year = year - 1900;

    info.tm_mon = month - 1;

    info.tm_mday = day;

    return mktime(&info);
}

int get_days(const char *from, const char *to)

{

    int year, month, day;

    sscanf(from, "%d-%d-%d", &year, &month, &day);

    int fromSecond = (int)convert(year, month, day);

    sscanf(to, "%d-%d-%d", &year, &month, &day);

    int toSecond = (int)convert(year, month, day);

    return (toSecond - fromSecond) / 24 / 3600;
}