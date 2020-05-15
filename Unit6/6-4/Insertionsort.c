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
    for (i = 0; i < size; i++)
        printf("%d\n", *(new + i));

    return 0;
}
void insertionSort(int *arr, int size)
{
    int i, j;
    for (i = 1; i < size; i++)
    {
        int tmp = arr[i];
        for (j = i; j > 0 && arr[j - 1] > tmp; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[j] = tmp;
    }
}
