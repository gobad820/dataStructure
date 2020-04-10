#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL));
    int number = rand() % 6 + 5;
    int *height = (int *)malloc(sizeof(int) * number);
    int max = 0;
    for (int i = 0; i < number; i++)
    {
        *(height + i) = rand() % 50 + 150;
        if (max < *(height + i))
            max = *(height + i);
    }
    printf("THE HEIGHT : %d", max);
    return 0;
}
