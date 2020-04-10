#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) \
    do                   \
    {                    \
        type t = x;      \
        x = y;           \
        y = t;           \
    } while (0)

int card_conv(unsigned x, int n, char d[]);
int main(int argc, char const *argv[])
{
    int no;
    int dno;
    int cd;
    char cno[100];
    puts("10진수를 기수 변환합니다");
    printf("변환하는 음이 아닌 정수 : ");
    scanf("%d", &no);
    printf("어떤 진수로 변환할까요?(2-36) : ");
    scanf("%d", &cd);
    dno = card_conv(no, cd, cno);
    for (int i = 0; i < dno; i++)
    {
        printf("%c", cno[i]);
    }
    printf("\n");

    return 0;
}
int card_conv(unsigned x, int n, char d[])
{
    int digit = 0;
    char dalpha[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (x == 0)
    {
        d[0] = dalpha[0];
    }
    else
    {
        while (x)
        {
            d[digit++] = dalpha[x % n];
            if (x == 1 || x == 0)
                printf("   ");
            if (x > 1)
                printf("%d |", n);
            printf("     %d", x);
            if (x != 1)
                printf("  *** %d\n", x % n);
            else
            {
                printf("\n");
            }

            if (x > 1)
                printf("   + -------\n");
            x /= n;
        }

        for (int i = 0; i < digit / 2; i++)
        {
            swap(char, d[i], d[digit - i - 1]);
        }
    }
    return digit;
}
