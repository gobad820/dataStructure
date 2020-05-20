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

void partition(int *arr, int left, int rifht);
void quickSort(int *arr, int size);
int main(int argc, char const *argv[])
{
	srand((unsigned)time(NULL));
	puts("배열을 나눕니다.");
	int size;
	printf("Enter the Size : ");
	scanf("%d", &size);

	int *arr = (int *)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++)
		printf("x[%d] = %d\n", i, arr[i] = rand() % 100);

	quickSort(arr, size);
	puts("오름차순으로 정렬했습니다.\n");
	for (int i = 0; i < size; i++)
		printf("x[%d] = %d\n", i, arr[i]);
	free(arr);
	return 0;
}

void quickSort(int *arr, int size)
{
	int left = 0;
	int right = size - 1;
	partition(arr, left, right);
}
void partition(int *arr, int left, int right)
{
	int pl = left;
	int pivot = arr[(right + left) / 2];
	int pr = right;

	int i;
	printf("a[%d] ~ a[%d] : {", left, right);
	for (i = left; i < right; i++)
		printf("%d ", arr[i]);
	printf("%d}\n", arr[right]);
	do
	{
		while (arr[pl] < pivot) // arr[pl]이 pivot보다 작으면 pl을 계속 이동
			pl++;
		while (arr[pr] > pivot) // arr[pr]이 pivot보다 크면 pr을 계속 이동
			pr--;
		if (pl <= pr)					 // pr과 pl이 서로 교차되지 않으면
		{								 //교차가 되거나 겹치면 두 배열로 나누는 작업이 끝났으므로
			swap(int, arr[pl], arr[pr]); // pr과 pl을 서로 교환
			pl++;
			pr--;
			// 그리고 pl과 pr서로 한칸씩 이동
		}
	} while (pl <= pr); // pl > pr 이면 두 그룹으로 나누는 작업 종료
	if (left < pr)
		partition(arr, left, pr);
	if (pl < right)
		partition(arr, pl, right);
}
