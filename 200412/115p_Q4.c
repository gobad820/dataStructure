#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int binary(int a[], int n, int key);
int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL));
    int i;
    int number = 10;
    printf("The Size of Array : %d\n", number);
    int *ptr = (int *)malloc(sizeof(int) * number);
    for (i = 0; i < number; i++)
    {
        // int flag = 0;
        // if (i == 0)
        *(ptr + i) = i;
        // else
        // {
        //     *(ptr + i) = rand() % 10;
        //     for (int a = 0; a < i; a++)
        //     {
        //         if (*(ptr + a) >= *(ptr + i) || *(ptr + i) > *(ptr + i - 1) + 20)
        //         {
        //             i--;
        //             flag = 1;
        //             break;
        //         }
        //     }
        //     /* code */
        // }

        // if (!flag)
        printf("ptr[%d] : %d\n", i, *(ptr + i));
    }
    int key;
    printf("Enter the number you want :");
    scanf("%d", &key);
    int result = binary(ptr, number, key);
    if (result != -1)
    {
        printf("%d는 ptr[%d]에 있습니다.\n", key, result);
    }
    else
    {
        printf("%d는 없는 값입니다.", key);
    }

    return 0;
}

int binary(int a[], int n, int key)
{
    int pl = 0;
    int pr = n - 1;
    int pc;
    int i;
    printf("   | ");
    for (i = 0; i < n; i++)
        printf(" %d  ", i);
    printf("\n");
    puts("---+------------------------------");

    do
    {
        pc = (pl + pr) / 2;
        printf("   |  ");
        for (i = 0; i < pl * 3 - 1; i++)
        {
            printf(" ");
        }
        printf("<-");
        for (i = 0; i < (pc - pl) * 3 - 1; i++)
            printf(" ");
        printf("+");
        for (i = 0; i < (pr - pc) * 3 - 1; i++)
            printf(" ");
        printf("->\n");
        printf("  %d|  ", pc);
        for (i = 0; i < n; i++)
            printf("%d  ", a[i]);
        printf("\n");
        printf("   |\n");

        if (a[pc] == key)
            return pc;
        else if (a[pc] < key)
        {

            pl = pc + 1;
        }
        else
        {

            pr = pc - 1;
        }
    } while (pl <= pr);
    return -1;
}
