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

//Bubble sort
void bubbleSort(int *arr, int size);
//Selection sort
void selectionSort(int *arr, int size);
//Insertion sort
void insertionSort(int *arr, int size);

int main(void)
{
    srand((unsigned)time(NULL));
    int size;
    printf("Enter the Size : ");
    scanf("%d", &size);
    int *arr = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 100;

    printf("Sort Number : ");
    int number;
    scanf("%d", &number);
    switch (number)
    {
    case 1:
        bubbleSort(arr, size);
        for (int i = 0; i < size; i++)
            printf("%d ", arr[i]);
        printf("\n");
        break;
    case 2:
        selectionSort(arr, size);
        for (int i = 0; i < size; i++)
            printf("%d ", arr[i]);
        printf("\n");
        break;
    case 3:
        insertionSort(arr, size);
        for (int i = 0; i < size; i++)
            printf("%d ", arr[i]);
        printf("\n");
        break;
    }

    return 0;
}

//Bubble sort
void bubbleSort(int *arr, int size)
{
    int i, j;
    for (i = 0; i < size - 1; i++)
    {
        for (j = i; j < size - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(int, arr[j], arr[j + 1]);
        }
    }
}
//Selection sort
void selectionSort(int *arr, int size)
{
    int i, j;
    for (i = 0; i < size - 1; i++)
    {
        int key = i;
        for (j = i; j < size; j++)
        {
            if (arr[key] > arr[j])
                key = j;
        }
        swap(int, arr[j], arr[key]);
    }
}
//Insertion sort
void insertionSort(int *arr, int size)
{
    int i, j;
    for (i = 1; i < size; i++)
    {
        int tmp = arr[i];
        for (j = i; j > 0 && arr[j - 1] > tmp; j--)
            arr[j] = arr[j - 1];
        arr[j] = tmp; // j가 이미 감소해 있다.
    }
}