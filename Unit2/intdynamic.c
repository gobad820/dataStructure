#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int *x = calloc(1, sizeof(int));
    if (x == NULL)
        puts("메모리 할당에 실패하였습니다");
    else
    {
        *x = 57;
        printf("*x= %d\n", *x);
        free(x);
    }

    return 0;
}
