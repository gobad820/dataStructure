#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binary(const int a[], int n, int key)
{
    int pl = 0;
    int pr = n - 1;
    int pc;
    do
    {
        pc = (pr + pl) / 2;
        if (key == a[pc])
            return pc;
        else if (a[pc] < key)

            pl = pc + 1;
        else
        {
            pr = pc - 1;
        }
    } while (pl <= pr);
    return -1;
}

int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL));
    puts("이진 검색");
    int check = 1;
    while (1)
    {
        check = 1;
        int number = rand() % 10 + 5;
        printf("요소 개수 : %d\n", number);
        puts("오름차순으로 입력하세요\n");
        int i;
        int a;
        int *sorted = (int *)malloc(sizeof(int) * number);
        for (i = 0; i < number; i++)
        {
            int flag = 0;
            *(sorted + i) = rand() % 20 + i;
            for (a = 0; a < i; a++)
            {
                if (*(sorted + a) >= *(sorted + i))
                {
                    i--;
                    flag = 1;
                    break;
                }
            }
            if (flag != 1)
                printf("x[%d] : %d\n", i, *(sorted + i));
        }
        int key;
        printf("검색값 : ");
        scanf("%d", &key);
        if (binary(sorted, number, key) != -1)
            printf("%d는(은) x[%d]에 있습니다.", key, binary(sorted, number, key));
        else
        {
            printf("%d는 없는 값입니다.", key);
        }
        printf("RETRY ? (1...YES / 0...NO)");
        scanf("%d", &check);
        if (check == 0)
            break;
        free(sorted);
    }

    return 0;
}
