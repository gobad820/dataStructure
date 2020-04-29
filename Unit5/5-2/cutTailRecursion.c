#include <stdio.h>

void recur(int n)
{
Top:
    if (n > 0)
    {
        recur(n - 1);
        printf("%d", n);
        n = n - 2;
        goto Top;
    }
}

int main(int argc, char const *argv[])
{
    int number;
    printf("정수를 입력하세요 : ");
    scanf("%d", &number);
    recur(number);

    return 0;
}
