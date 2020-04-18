#include <stdio.h>
#include <stdlib.h>

int sum(int a, int b)
{
    return a + b;
}

int mul(int a, int b)
{
    return a * b;
}

// void funcPtr(int (*calc)(int, int)) // 함수 포인터는 주소값을 적는게 아닌 이름만 적는다. 배열의 이름이 배열의 주소를 나타내는것과 동일함
void funcPtr(int calc(int, int))
{
    int i, j;
    for (i = 1; i < 10; i++)
    {
        for (j = 1; j < 10; j++)
        {
            // printf("%3d", (*calc)(i, j));
            printf("%3d", (calc)(i, j)); //매개변수에 int *a 와 int a[]가 같듯이 함수 이름만 써도 허용이 된다.
        }
        putchar('\n');
    }
}

int main(int argc, char const *argv[])
{
    puts("덧셈표");
    funcPtr(sum);
    puts("곱셈표");
    funcPtr(mul);
    return 0;
}
