#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linear(int a[], int n, int key)
{
    a[n] = key;
    int i;
    printf("   | ");
    for (i = 0; i < n; i++)
        printf("%d ", i);
    printf("\n---+-----------------------------\n");
    for (i = 0; i <= n; i++)
    {

        printf("   | ");
        for (int s = 0; s < i * 2; s++)
        {
            // if (a[i] >= 10)
            //     printf(" ");
            printf(" ");
        }
        printf("*\n");
        printf("  %d| ", i);
        for (int j = 0; j < n; j++)
        {
            printf("%d ", a[j]);
        }
        printf("\n");
        if (a[i] == key)
            break;
    }
    printf("\n");
    return i;
} // 보초법 복습
int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL));
    int i;
    int key;
    int number = rand() % 10 + 5;
    int *arr = (int *)malloc(sizeof(int) * number);
    printf("The Size of Array : %d\n", number);
    for (i = 0; i < number; i++)
    {
        int flag = 0;
        *(arr + i) = rand() % 10;
        for (int a = 0; a < i; a++)
        {
            if (*(arr + i) == *(arr + a))
            {
                flag = 1;
                i--;
                break;
            }
        }
        if (flag != 1)
            printf("arr[%d] : %d\n", i, *(arr + i));
    }
    printf("Enter the number be searched  : ");
    scanf("%d", &key);
    int result = linear(arr, number, key);
    if (result != number)
        printf("%d는(은) arr[%d]에 있습니다.", key, result);
    else
    {
        printf("%d는(은) 없는 값입니다.", key);
    }
    return 0;
}
