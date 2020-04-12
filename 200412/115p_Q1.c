#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int search_idx(const int a[], int n, int key, int idx[]); // 중복되는 수까지 return
int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL));
    int i;
    int key;
    int number = rand() % 10 + 5;
    int *arr = (int *)malloc(sizeof(int) * number);
    int index[100];
    printf("The Size of Array : %d\n", number);
    for (i = 0; i < number; i++)
    {
        int flag = 0;
        *(arr + i) = rand() % 10;
        // for (int a = 0; a < i; a++)
        // {
        //     if (*(arr + i) == *(arr + a))
        //     {
        //         flag = 1;
        //         i--;
        //         break;
        //     }
        // }
        // if (flag != 1)
        printf("arr[%d] : %d\n", i, *(arr + i));
    }
    printf("Enter the number be searched  : ");
    scanf("%d", &key);
    int result = search_idx(arr, number, key, index);
    if (result)
    {
        printf("%d는(은) ", key);
        for (i = 0; i < result; i++)
        {
            printf("| arr[%d] | ", index[i]);
        }
        printf("에 총 %d개 있습니다.\n", result);
    }
    else
    {
        printf("%d는(은) 없는 값입니다.", key);
    }
    return 0;
}

int search_idx(const int a[], int n, int key, int idx[]) // 중복되는 수까지 return
{
    int i;
    int index = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            idx[index] = i;
            index++;
        }
    }
    return index;
}