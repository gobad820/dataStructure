#include <stdio.h>

int mdays[][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}}; // 열의 개체 수는 적어 주어야 한다.

typedef struct
{
    int year;
    int month;
    int date;
} Date;

Date DateOf(int y, int m, int d);
Date After(Date x, int n);
Date Before(Date x, int n);

int main(int argc, char const *argv[])
{
    Date a = {2020, 3, 5};
    printf("연도 : %d", a.year);
    // DateOf()

    return 0;
}
