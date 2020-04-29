#include <stdio.h>

int GCD(int bigNumber, int smallNumber);
int main(int argc, char const *argv[])
{
    puts("두 정수의 최대공약수를 구합니다.");
    int bigNumber, smallNumber;
    printf("정수를 입력하세요 : ");
    scanf("%d", &bigNumber);
    printf("정수를 입력하세요 : ");
    scanf("%d", &smallNumber);
    printf("최대 공약수는 %d입니다.", GCD(bigNumber, smallNumber));
    return 0;
}

int GCD(int bigNumber, int smallNumber)
{
    if (smallNumber == 0)
    {
        return bigNumber;
        //결국 마지막에 return 되는값이 GCD(bigNum,smallNum)의 값이다
    }
    else
    {
        return GCD(smallNumber, bigNumber % smallNumber);
    }
}