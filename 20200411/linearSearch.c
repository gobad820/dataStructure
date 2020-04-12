#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int search(const int a[], int n, int key)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] == key)
            return i;
    }
    return -1;
}
int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL));
    int j;
    do
    {
        int number = rand() % 10 + 5;
        puts("선형 검색");
        printf("요소 개수 : %d\n", number);
        int *x = (int *)malloc(sizeof(int) * number);
        for (int i = 0; i < number; i++)
        {
            int flag = 0;
            *(x + i) = rand() % 20;
            for (int a = 0; a < i; a++)
            {
                if (*(x + a) == *(x + i))
                {
                    i--;
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
                printf("x[%d] : %d\n", i, *(x + i));
        }
        int key;
        printf("검색값 : ");
        scanf("%d", &key);
        if (search(x, number, key) != -1)
        {
            printf("%d은(는) x[%d]에 있습니다.\n", key, search(x, number, key));
        }
        else
        {
            printf("%d는 없는 값입니다.\n", key);
        }

        puts("RETRY? Yes...1/No...0");
        scanf("%d", &j);
        free(x);
    } while (j != 0);

    puts("PROGRAM CLOSING");

    return 0;
}
