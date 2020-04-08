#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int maxof(const int arr[], int number)
{
    int max = *arr;
    for (int i = 1; i < number; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
    return max;
}
int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL));
    // seed random -> srand
    int number;
    int i = 0;
    printf("사람 수 : ");
    scanf("%d", &number);
    int *a = (int *)malloc(sizeof(int) * number);
    // printf("%d 사람의 키를 입력하세요.\n", number);
    for (i = 0; i < number; i++)
    {
        *(a + i) = rand() % 70 + 150; // 150 ~ 150 + 69
        printf("height[%d] : %d\n", i, *(a + i));
    }
    printf("최댓값은 %d입니다.", maxof(a, number));
    free(a);

    return 0;
}
