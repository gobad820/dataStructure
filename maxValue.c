#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int max = a;
    if (b > max)
        max = b;
    if (c > max)
        max = c;

    printf("%d", max);
    // if (a > b && a > c)
    //     printf("%d", a);
    // if (b > a && b > c)
    //     printf("%d", b);
    // if (c > b && c > a)
    //     printf("%d", c);
    return 0;
}
