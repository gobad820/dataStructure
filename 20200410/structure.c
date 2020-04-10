#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define number 10
typedef struct
{
    char name[20];
    double height;
    double eyesight;
    double eyegrade;
} Std;

double eyechecker(double eyesight);

int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL));

    Std *std = (Std *)malloc(sizeof(Std) * number);
    int i;
    for (i = 0; i < number; i++)
    {
        *(std + i)->name = 'A' + i;
        (std + i)->height = (double)(rand() % 40 + 150);
        (std + i)->eyesight = (double)(rand() % 200) / 100;
    }

    double max = 0;
    double average;

    puts("⬛️⬜️⬛️ 신체검사 표 ⬛️⬜️⬛️");
    puts("이름      키      시력");
    for (i = 0; i < number; i++)
    {
        printf(" %s      %.0f      %.2f \n", ((std + i)->name), (std + i)->height, (std + i)->eyesight);
        max += (std + i)->height;
        (std + i)->eyegrade = eyechecker((std + i)->eyesight);
    }
    average = max / number;
    printf("평균 키 : %f\n", average);
    puts("시력 분포");
    double j;
    for (j = 1; j <= 20; j++)
    {
        int eNum = 0;
        for (int a = 0; a < number; a++)
        {
            if ((std + a)->eyegrade == j)
                eNum++;
        }
        printf("%.1f~ :", (j - 1) / 10);
        for (i = 0; i < eNum; i++)
            printf("*");
        printf("\n");
    }

    return 0;
}

double eyechecker(double eyesight)
{
    double eyecheck = 0;
    for (double i = 1; i <= 20; i++)
        if (eyesight < (i / 10) && eyesight >= (i - 1) / 10)
        {
            eyecheck = i;
            break;
        }
    return eyecheck;
}