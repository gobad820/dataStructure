#include <stdio.h>

int factorial(int number);
int main(int argc, char const *argv[])
{
    int number;
    printf("Enter The Integer : ");
    scanf("%d", &number);
    printf("%d의 순차곱셈 값은 %d입니다.", number, factorial(number));
    return 0;
}
int factorial(int number)
{
    if (number != 1)
        return number * factorial(number - 1);
    else
        return 1;
}
