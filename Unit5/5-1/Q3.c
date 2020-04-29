// 배열 a의 모든 요소의 최대 공약수를 구하는 다음 함수를 작성하세요.

#include <stdio.h>
int gcd(int bigNumber, int smallNumber);
int gcd_array(const int a[], int n);
int main(int argc, char const *argv[])
{
    int number;
    int i;
    printf("배열의 크기 : ");
    scanf("%d", &number);
    int arr[number];
    puts("배열의 원소를 입력해주십시오.");
    for (i = 0; i < number; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("배열의 최대 공약수 : %d", gcd_array(arr, number));
    return 0;
}
int gcd(int bigNumber, int smallNumber)
{
    if (smallNumber == 0)
        return bigNumber;
    else
    {
        return gcd(smallNumber, bigNumber % smallNumber);
    }
}

int gcd_array(const int a[], int n)
{
    int i;
    int result;
    if (a[0] > a[1])
        result = gcd(a[0], a[1]);
    else
        result = gcd(a[1], a[0]);

    for (i = 1; i < n - 1; i++)
    {
        if (result > a[i + 1])
            result = gcd(result, a[i + 1]);
        else
            result = gcd(a[i + 1], result);
    }
    return result;
}
