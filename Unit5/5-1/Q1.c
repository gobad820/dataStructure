#include <stdio.h>

int factorialNonR(int number);
int main(int argc, char const *argv[])
{
    int number;
    printf("Enter the number : ");
    scanf("%d", &number);
    printf("The Result is %d", factorialNonR(number));
    return 0;
}

int factorialNonR(int number)
{
    int i;
    int result = 1;
    for (i = 1; i <= number; i++)
    {
        result *= i;
    }
    return result;
}