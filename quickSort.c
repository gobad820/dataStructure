#include <stdio.h>

int number = 10;
int data[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};

void quickSort(int *data, int start, int end)
{
    // start 는 첫번째 집합의 첫 수
    // end는 마지막 집합의 마지막 수
    if (start >= end)
    { // 원소가 1개인 경우
        return;
    }
    int key = start;   // 키는 첫번째 원소 // key = pivot
    int i = start + 1; // 왼쪽 출발 지점
    int j = end;       // 오른쪽 출발 지점
    int temp;

    while (i <= j)
    { //엇갈릴 때까지 반복 // 왼쪽 출발지점이 오른쪽 출발지점보다 작거나 같을 때
        while (i <= end && data[i] <= data[key])
        { // 키 값보다 큰 값을 만날때까지 i++
            i++;
        }
        while (data[j] >= data[key] && j >= start)
        { //키 값보다 작은 값을 만날때까지 반복
            j--;
        }
        if (i > j)
        { //현재 엇갈린 상태면 키 값과 교체
            temp = data[j];
            data[j] = data[key];
            data[key] = temp;
        }
        else
        {
            temp = data[j];
            data[j] = data[i];
            data[i] = temp;
        }

        quickSort(data, start, j - 1);
        quickSort(data, j + 1, end);
    }
}
int main(int argc, char const *argv[])
{
    quickSort(data, 0, number - 1);
    for (int i = 0; i < number; i++)
        printf("%d ", data[i]);
    return 0;
}
