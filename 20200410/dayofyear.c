// 한 해의 지난 날 수를 구합니다
#include <stdio.h>
#include <stdbool.h>
// 각 달의 날 수
int mdays[][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}}; // 열의 개체 수는 적어 주어야 한다.

// year년이 윤년인가?
int isLeap(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

// y년 m월 d일의 그 해 지난 날 수를 구합니다
int dayofyear(int lyear, int month, int day)
{
    int days = day;
    for (int i = 0; i < month - 1; i++)
    {
        days += mdays[lyear][i];
    }
    return days;
}

int main(int argc, char const *argv[])
{
    int i = 0;
    int year;
    int month;
    int day;
    do
    {
        printf("년 : ");
        scanf("%d", &year);
        printf("월 : ");
        scanf("%d", &month);
        printf("일 : ");
        scanf("%d", &day);

        printf("%d년의 %d일쨰입니다.", year, dayofyear(isLeap(year), month, day));
        printf("다시 할까요?(1...예 / 0...아니요)\n");
        scanf("%d", &i);
    } while (i);

    puts("프로그램을 종료합니다.");
    return 0;
}
