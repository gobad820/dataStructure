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

void SelectionSort(int *arr, int size);
int main(int argc, char const *argv[])
{
    int size;
    srand((unsigned)time(NULL));
    printf("Size : ");
    scanf("%d", &size);
    int *arr = (int *)malloc(sizeof(int) * size);
    int i;
    for (i = 0; i < size; i++)
        *(arr + i) = rand() % 90 + 10;

    SelectionSort(arr, size);
    // for (i = 0; i < size; i++)
    //     printf("%d\n", *(arr + i));

    return 0;
}

void SelectionSort(int *arr, int size)
{
    int i, j;
    for (i = 0; i < size - 1; i++)
    {
        int key = i;
        for (j = i; j < size; j++)
        {
            if (arr[j] < arr[key])
                key = j;
        }
        int k;
        for (k = 0; k < i; k++)
            printf("   ");
        printf("*");
        if (key - i == 0)
        {
            printf("\n");
        }
        else
        {
            for (k = 0; k < key - i; k++)
            {
                printf("   ");
            }
            printf("+");
            printf("\n");
        }

        for (j = 0; j < size; j++)
            printf("%2d ", arr[j]);
        printf("\n");

        swap(int, arr[i], arr[key]);
    }
}