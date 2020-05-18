#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define swap(type, x, y) \
    do                   \
    {                    \
        type t = x;      \
        x = y;           \
        y = x;           \
    } while (0)

void shellSort(int *arr, int size);
void shellSort2(int *arr, int size);
int shellSortcheck(int *arr, int size);
int shellSort2check(int *arr, int size);
int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL));
    int size;
    printf("Enter the Size : ");
    scanf("%d", &size);

    int *arr = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 100;

    int check = shellSort2check(arr, size);
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\n%d", check);
    free(arr);
    return 0;
}

void shellSort(int *arr, int size) // Insertion 분할해서 시작
{
    int i, j, h;
    for (h = size / 2; h > 0; h /= 2)
    {
        for (i = h; i < size; i++)
        {
            int tmp = arr[i];
            for (j = i - h; j >= 0 && tmp < arr[j]; j -= h)
                arr[j + h] = arr[j]; // arr[j+h]는 이미 tmp에 저장이 되어 있으므로
            arr[j + h] = tmp;
            //반복이 돌지 않으면 j = i-h 이므로 arr[i] = arr[j+h]이다
            //반복이 돈다면 j = i -( h * 반복횟수 )이므로 arr[i] != arr[j+h]
        }
    }
}

void shellSort2(int *arr, int size)
{
    int i, j, h;
    for (h = 1; h < h / 9; h = h * 3 + 1) // 반복 횟수를 h /9 의 값을 최대로 *3 +1씩 늘려감
        ;
    for (; h > 0; h /= 3) // 최대값에서 /3 하면서 반복
        for (i = h; i < size; i++)
        {
            int tmp = arr[i];
            for (j = i - h; j >= 0 && arr[j] > tmp; j -= h)
                arr[j + h] = arr[j];
            arr[j + h] = tmp;
        }
}

int shellSortcheck(int *arr, int size) // Insertion 분할해서 시작
{
    int i, j, h;
    int check;
    for (h = size / 2; h > 0; h /= 2)
    {
        for (i = h; i < size; i++)
        {
            int tmp = arr[i];
            for (j = i - h; j >= 0 && tmp < arr[j]; j -= h)
            {
                arr[j + h] = arr[j]; // arr[j+h]는 이미 tmp에 저장이 되어 있으므로
                check++;
            }
            arr[j + h] = tmp;
            //반복이 돌지 않으면 j = i-h 이므로 arr[i] = arr[j+h]이다
            //반복이 돈다면 j = i -( h * 반복횟수 )이므로 arr[i] != arr[j+h]
        }
    }
    return check;
}

int shellSort2check(int *arr, int size)
{
    int check = 0;
    int i, j, h;
    for (h = 1; h < h / 9; h = h * 3 + 1) // 반복 횟수를 h /9 의 값을 최대로 *3 +1씩 늘려감
        ;
    for (; h > 0; h /= 3) // 최대값에서 /3 하면서 반복
        for (i = h; i < size; i++)
        {
            int tmp = arr[i];
            for (j = i - h; j >= 0 && arr[j] > tmp; j -= h)
            {
                arr[j + h] = arr[j];
                check++;
            }
            arr[j + h] = tmp;
        }
    return check;
}