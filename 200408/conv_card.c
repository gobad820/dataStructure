#include <stdio.h>
int card_convrt(unsigned x, int n, char d[]);

int main(int argc, char const *argv[])
{
    int i;
    unsigned no;
    int cd;
    int dno;
    char cno[512];
    int retry;
    puts("10진수를 기수 변환합니다.");
    do
    {
        printf("변환하는 음이 아닌 정수 : ");
        scanf("%u", &no);
        do
        {
            printf("어떤 진수로 변환할까요?(2-36) : ");
            scanf("%d", &cd);
        } while (cd < 2 || cd > 36);
        dno = card_convrt(no, cd, cno);
        printf("%d진수로는", cd);
        for (i = dno - 1; i >= 0; i--) // 역순으로 입력이 되었기 때문에 다시 역순으로 출력해야 올바른 순서로 출력이 됨
            printf("%c", cno[i]);
        printf("입니다.\n");
        printf("한 번 더 할까요?(1 ... 예 / 2 ... 아니요) : ");
        scanf("%d", &retry);
    } while (retry == 1);
    return 0;
}

int card_convrt(unsigned x, int n, char d[])
{
    char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    //나올 수 있는 모든 나머지들로 dchar을 초기화
    int digits = 0;
    //나머지의 자리수
    if (x == 0) // 수가 0 이면 그대로 0을 넣고 종료
        d[digits++] = dchar[0];
    else
    {
        while (x) // x != 0 이면 반복
        {
            d[digits++] = dchar[x % n]; //기수 변환한 수를 역순으로 d배열에 입력
            x /= n;
        }
    }
    return digits;
}