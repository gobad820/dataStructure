#include <stdio.h>

void recur(int n);

int main(int argc, char const *argv[])
{
    int number;
    printf("정수를 입력하세요 : ");
    scanf("%d", &number);
    recur(number);

    return 0;
}
void recur(int n)
{
    if (n > 0)
    {
        recur(n - 1);
        printf("%d", n);
        recur(n - 2);
    }
}