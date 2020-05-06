#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) \
    do                   \
    {                    \
        type t = x;      \
        x = y;           \
        y = t;           \
    } while (0)

void bubblestop(int *arr, int size);
void bubbleSort2(int *arr, int size);
void bubbleSort3(int *arr, int size);
void bubbleSort(int *arr, int size);
int is_sorted(const int a[], int n);
int main(int argc, char const *argv[])
{
    int size;
    printf("Size : ");
    scanf("%d", &size);
    int *arr = (int *)malloc(sizeof(int) * 10);
    for (int i = 0; i < size; i++)
    {
        printf(" %d's Value : ", i);
        scanf("%d", arr + i);
    }
    bubbleSort3(arr, size);
    return 0;
}
void bubbleSort(int *arr, int size)
{
    int i, j;
    for (i = 0; i < size - 1; i++)
    {
        for (j = i; j < size - 1; j++)
        {
            int number = -1;
            if (arr[j] > arr[j + 1])
            {
                swap(int, arr[j], arr[j + 1]);
                number = j;
            }

            for (int k = 0; k < size; k++)
            {
                if (k == number)
                    printf("%d+", arr[k]);
                else
                {
                    if (k == j)
                    {
                        printf("%d-", arr[k]);
                    }
                    else
                    {
                        printf("%d ", arr[k]);
                    }
                }
            }
            printf("\n");
        }
    }
}

int is_sorted(const int a[], int n)
{
    int i;
    for (i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1]) // 어떤 패스에서라도 교환이 없는가??
            return 1;        // 있으면 정렬이 되지 않음
    }
    return 0; // 없으면 정렬 완료
}

void bubblestop(int *arr, int size)
{
    int i, j;
    for (i = 0; i < size - 1; i++)
    {
        int exchange = 0;
        for (j = size - 1; j > i; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(int, arr[j], arr[j - 1]);
                exchange++;
            }
        }
        if (exchange == 0)
        {
            break;
        }
    }
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}
void bubbleSort2(int *arr, int size)
{
    int i, j;
    for (i = 0; i < size - 1; i++)
    {
        for (j = size - 1; j > i; j--)
        {
            if (arr[j] < arr[j - 1])
                swap(int, arr[j], arr[j - 1]);
        }
    }
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

void bubbleSort3(int *arr, int size)
{
    int k = 0;
    while (k < size - 1)
    {
        int j;
        int last = 0;
        for (j = k; j < size - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(int, arr[j], arr[j + 1]);
                last = j;
            }
        }
        k = last;
    }
    for (k = 0; k < size; k++)
        printf("%d ", arr[k]);
    printf("\n");
}