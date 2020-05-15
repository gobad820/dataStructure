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

void insertionSort(int *arr, int size);
int main(int argc, char const *argv[])
{
    int size;
    srand((unsigned)time(NULL));
    printf("Size : ");
    scanf("%d", &size);
    int *arr = (int *)malloc(sizeof(int) * size);
    int *new = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &new[i]);
    }
    int i;
    for (i = 0; i < size; i++)
        *(arr + i) = rand() % 100;

    insertionSort(new, size);
    return 0;
}
void insertionSort(int *arr, int size)
{
    int i, j;
    for (i = 1; i < size; i++)
    {
        int tmp = arr[i];
        for (int k = 0; k < size; k++)
        {
            printf("%2d", arr[k]);
        }
        printf("\n");

        for (j = i; j > 0 && arr[j - 1] > tmp; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[j] = tmp;
        if (arr[i] == arr[j])
        {
            for (int m = 0; m < j; m++)
            {
                printf("   ");
            }
            printf("+");
            printf("\n");
        }
        else
        {
            printf("^--");
            for (int k = 0; k < i - 1; k++)
                printf("---");
            printf("+");
            printf("\n");
        }
    }
}
