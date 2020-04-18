#include <stdio.h>
#include <stdlib.h>

int int_cmp(const int *a, const int *b)
{
    if (*a < *b)
        return 1;
    else if (*a == *b)
        return 0;
    else
    {
        return -1;
    }
}
int main(int argc, char const *argv[])
{
    printf("bsearch 함수를 사용하여 검색\n");
    int number;
    printf("요소 개수 : ");
    scanf("%d", &number);
    printf("\n내림차순으로 입력하세요.");
    int *ptr = (int *)malloc(sizeof(int) * number);
    int i;
    for (i = 0; i < number; i++)
    {
        printf("x[%d] : ", i);
        scanf("%d", ptr + i);
    }
    int key;
    printf("검색값 :");
    scanf("%d", &key);
    int *p = bsearch(&key, ptr, number, sizeof(int), (int (*)(const void *, const void *))int_cmp);
    if (p)
        printf("%d은(는) x[%d]에 있습니다", key, (int)(p - ptr));
    else
    {
        printf("%d은(는) 없는 값입니다.", key);
    }
    free(ptr);
    return 0;
}
