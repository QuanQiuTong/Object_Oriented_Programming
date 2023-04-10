#include <time.h>
#include <stdio.h>
int main()
{
    /* time_t s = -1;
    struct tm *t = gmtime(&s);
    puts(asctime(t)); */

    struct tm t = {0}, *preal;

    // t.tm_year = -2;
    t.tm_isdst = 1;
    puts(asctime(&t));
    time_t s = mktime(&t), realtime = time(NULL);
    printf("real time: %d == %d\n", mktime(preal = gmtime(&realtime)), time(NULL));
    for (int i = 0; i < sizeof(struct tm) / sizeof(int); ++i)
        printf("[%d]: %d\n", i, *((int *)preal + i));

    printf("%d %lf\n", s, difftime(0, s));
}