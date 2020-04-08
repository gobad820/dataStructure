#include <stdio.h>
#include <stdlib.h>
//  TODO: swap함수 define에서 해결할수 있음
#define swap(type, x, y) \
    do                   \
    {                    \
        type t = x;      \
        x = y;           \
        y = t;           \
    } while (0)

int *reverse(int *array, int number);
void ary_reverse(int a[], int n);
int main(int argc, char const *argv[])
{
    int number;
    printf("요소의 개수 : ");
    scanf("%d", &number);
    printf("%d개의 정수를 입력하세요.\n", number);
    int *array = (int *)malloc(sizeof(int) * number);
    int i = 0;
    for (i = 0; i < number; i++)
    {
        printf("x[%d] : ", i);
        scanf("%d", array + i);
    }
    ary_reverse(array, number);
    puts("배열의 요소를 역순으로 정렬했습니다.");
    for (i = 0; i < number; i++)
    {
        printf("x[%d] = %d\n", i, *(array + i));
    }
    return 0;
}
// int *reverse(int *array, int number)
// {
//     int *new = (int *)malloc(sizeof(int) * number);
//     int size = number - 1; // size = 4
//     for (int i = size; i >= 0; i--)
//     {
//         *(new + size - i) = *(array + i);
//     }
//     for (int j = 0; j < number; j++)
//     {
//         *(array + j) = *(new + j);
//     }
//     free(new);
//     return array;
// }

void ary_reverse(int a[], int n)
{
    int i;
    for (i = 0; i < n / 2; i++)
    {
        swap(int, a[i], a[i + n - 1]);
    }

    //하나씩 하지 않고도 2로 나눈 후 중간값을 제외하고 1,n   2,n-1   3,n-2 ***** n/2-1, n/2+1(홀수일 경우)
}
