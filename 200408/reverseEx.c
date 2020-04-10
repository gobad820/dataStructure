#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define swap(type, x, y) \
    do                   \
    {                    \
        type t = x;      \
        x = y;           \
        y = t;           \
    } while (0)

void arr_reverse(int a[], int n);

int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL));
    int number = rand() % 5 + 5;
    printf("The Size of Array : %d\n", number);
    int *arr = (int *)malloc(sizeof(int) * number);
    for (int i = 0; i < number; i++)
    {
        *(arr + i) = rand() % 50 + 3;
        printf("%d ", *(arr + i));
    }
    printf("\n");
    puts("REVERSE");
    arr_reverse(arr, number);
    free(arr);

    return 0;
}

void arr_reverse(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", *(a + i));
    printf("\n");
    for (int i = 0; i < n / 2; i++)
    {

        printf("arr[%d]와 arr[%d]를 교환합니다.\n", i, n - i - 1);
        swap(int, a[i], a[n - 1 - i]);
        for (int i = 0; i < n; i++)
            printf("%d ", *(a + i));
        printf("\n");
    }
}
