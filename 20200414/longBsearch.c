#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int longcmp(const long *a, const long *b);
int main(int argc, char const *argv[])
{
    long alpha[10] = {192375, 2837, 1985, 1852, 1625, 1432, 1333, 1201, 1111, 1000};
    int retry;
    long key;
    do
    {
        puts("수를 검색합니다");
        printf("수 : ");
        scanf("%ld", &key);
        long *p = bsearch(&key, alpha, sizeof(alpha) / sizeof(long), sizeof(long), (int (*)(const void *, const void *))longcmp);
        //bsearch의 매개변수 주의
        if (p == NULL)
            puts("검색에 실패하였습니다.");
        else
        {
            puts("검색 성공 !! 아래의 요소를 찾았습니다.");
            printf("x[%d] : %ld\n", (int)(p - alpha), key);
        }
        printf("다시 검색할까요?(1)..예 / (0)..아니요 : ");
        scanf("%d", &retry);
    } while (retry == 1);

    return 0;
}
int longcmp(const long *a, const long *b)
{
    if (*a > *b)
        return -1;
    else if (*a == *b)
        return 0;
    else
    {
        return 1;
    }
}
