#include <stdio.h>
int GCDNR(int bigNumber, int smallNumber);
int main(int argc, char const *argv[])
{
    int big, small;
    printf("Enter the big Integer : ");
    scanf("%d", &big);
    printf("Enter the small Integer : ");
    scanf("%d", &small);
    printf("The Greater Common Demand : %d", GCDNR(big, small));
    return 0;
}

int GCDNR(int bigNumber, int smallNumber)
{
    int remain;
    while (smallNumber != 0)
    {
        remain = bigNumber % smallNumber;
        bigNumber = smallNumber;
        smallNumber = remain;
    }
    return bigNumber;
}