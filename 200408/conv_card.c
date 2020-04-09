#include <stdio.h>
#include <stdlib.h>
// 정수 값x를 n진수로 변환하여 배열 d에 아랫자리부터 저장
#define swap(type, x, y) \
    do                   \
    {                    \
        type t = x;      \
        x = y;           \
        y = t;           \
    } while (0)

// int card_convr(unsigned x, int n, char d[])
// {
//     //2진수
//     if (n == 2)
//     {
//     }
//     //8진수
//     else if (n == 8)
//     {
//     }
//     //16진수
//     else if (n == 16)
//     {
//     }
//     else
//     {
//         /* code */
//     }
// }

void card(unsigned x, int n, char d[])
{

    int number = 0;
    for (int i = 0; x != 0; i++)
    {
        *(d + i) = (char)(x % n);
        if (x == 1)
        {
            *(d + i) = '1';
        }
        x = x / n;
        number++;
    }
    for (int i = 0; i < number / 2; i++)
    {
        swap(int, d[i], d[i + number - 1]);
    }
    for (int j = 0; j < number; j++)
        printf("%c", d[j]);
}

int main(int argc, char const *argv[])
{
    int a = 5;
    char *new = (char *)malloc(sizeof(char) * 100);
    card(a, 2, new);
    return 0;
}
