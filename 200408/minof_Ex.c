#include <stdio.h>
#include <stdlib.h>

int minof(const int a[], int n)
{
    int min = a[0];
    for (int i = 1; i < n; i++)
    {
        if (min > a[i])
            min = a[i];
    }
    return min;
}

int sumof(const int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    return sum;
}

double aveof(const int a[], int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    double ave = sum / n;
    return ave;
}
int main(int argc, char const *argv[])
{
    int number;
    printf("number : ");
    scanf("%d", &number);
    int *arr = (int *)malloc(sizeof(int) * number);
    for (int i = 0; i < number; i++)
    {
        scanf("%d", arr + i);
    }
    printf("The minimum value : %d", minof(arr, number));
    printf("The Sum of values : %d", sumof(arr, number));
    printf("The Average of values : %f", aveof(arr, number));
    return 0;
}
