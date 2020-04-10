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

void ary_copy(int a[], const int b[], int n)
{

    for (int i = 0; i < n; i++)
    {
        *(a + i) = *(b + i);
    }
}

void ary_cpyrev(int a[], const int b[], int n)
{
    ary_copy(a, b, n);
    for (int i = 0; i < n / 2; i++)
    {
        swap(int, a[i], a[n - i - 1]);
    }
}

void shuffle(int a[], int n) // 모든 요소의 순서를 뒤섞는
{
    int number = rand() & n;
    for (int i = 0; i < n; i++)
    {
    }
}
int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL));
    int i = 0;
    int number;
    printf("NUMBER: ");
    scanf("%d", &number);
    int *arr = (int *)malloc(sizeof(int) * number);
    int *newarr = (int *)malloc(sizeof(int) * number);
    printf("ARRAY : ");
    for (i = 0; i < number; i++)
    {
        *(arr + i) = rand() % 50;
        printf("%d ", *(arr + i));
    }
    printf("\n");
    printf("NEW ARRAY : ");
    ary_cpyrev(newarr, arr, number);
    for (i = 0; i < number; i++)
        printf("%d ", *(newarr + i));
    printf("\n");
    printf("NEW ARRAY SHUFFLE : ");
    shuffle(newarr, number);
    for (i = 0; i < number; i++)
        printf("%d ", *(newarr + i));

    free(arr);
    free(newarr);
    return 0;
}
