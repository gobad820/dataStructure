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

void cocktailSort(int *arr, int n);
void bubbleSort(int *arr, int n);
void bubbleSort_s(int *arr, int n);
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

    cocktailSort(arr, size);
    for (i = 0; i < size; i++)
        printf("%d\n", *(arr + i));

    return 0;
}
void bubbleSort(int *arr, int n)
{
    int k = 0;
    while (k < n - 1)
    {
        int j;
        int last = n - 1;
        for (j = n - 1; j > k; j--)
        {
            if (arr[j - 1] > arr[j])
            {
                swap(int, arr[j - 1], arr[j]);
                last = j;
            }
        }
        k = last;
    }
}

void bubbleSort_s(int *arr, int n)
{
    int k = n - 1;
    int number = 0;
    while (k > 0)
    {
        int j;
        int last = 0;
        for (j = 0; j < k; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(int, arr[j], arr[j + 1]);
                last = j + 1;
            }
        }
        k = last;
    }
}

void cocktailSort(int *arr, int n)
{
    int number = 0;
    if (number % 2 == 0)
    {
        number++;
        int k = 0;
        while (k < n - 1)
        {
            int j;
            int last = n - 1;
            for (j = n - 1; j > k; j--)
            {
                if (arr[j - 1] > arr[j])
                {
                    swap(int, arr[j - 1], arr[j]);
                    last = j;
                }
            }
            k = last;
        }
    }
    else
    {
        number++;
        int k = n - 1;
        while (k > 0)
        {
            int j;
            int last = 0;
            for (j = 0; j < k; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(int, arr[j], arr[j + 1]);
                    last = j + 1;
                }
            }
            k = last;
        }
    }
}