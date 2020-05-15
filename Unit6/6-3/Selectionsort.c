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

void selectionSort(int *arr, int size);
int main(int argc, char const *argv[])
{
    int size;
    srand((unsigned)time(NULL));
    printf("Size : ");
    scanf("%d", &size);
    int *arr = (int *)malloc(sizeof(int) * size);
    int i;
    for (i = 0; i < size; i++)
        *(arr + i) = rand() % 100;

    selectionSort(arr, size);
    for (i = 0; i < size; i++)
        printf("%d\n", *(arr + i));

    return 0;
}
void selectionSort(int *arr, int size)
{
    int min;
    int i;
    int j;
    for (i = 0; i < size - 1; i++)
    {
        min = i;
        for (j = i + 1; j < size; j++)
        {
            if (arr[min] < arr[j])
                min = j;
            swap(int, arr[min], arr[j]);
        }
    }
}
