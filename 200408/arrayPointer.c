#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

    int *a;
    int b;
    int i = 0;
    printf("요소 개수 : ");
    scanf("%d", &b);
    a = calloc(b, sizeof(int));
    printf("%d개의 정수를 입력하세요.\n", b);
    for (i = 0; i < b; i++)
    {
        printf("a[%d] : ", i);
        scanf("%d", a + i);
    }
    puts("각 요소값은 아래와 같습니다");
    for (i = 0; i < b; i++)
        printf("a[%d] = %d\n", i, a[i]);

    free(a);

    return 0;
}

/* calloc을 이용해서 사용 
    요소 개수 :4
    4개의 정수를 입력하세요.
    a[0] : 10
    a[1] : 73
    a[2] : 2
    a[3] : -5
    각 요소값은 아래와 같습니다
    a[0] = 10
    a[1] = 73
    a[2] = 2
    a[3] = -5*/
