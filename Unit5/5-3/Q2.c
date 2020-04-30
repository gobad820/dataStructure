#include <stdio.h>

void move(int no, char x, char y);

int main(int argc, char const *argv[])
{
    int number;
    puts("하노이의 탑");
    printf("원반 개수 : ");
    scanf("%d", &number);
    move(number, 'A', 'C');
    return 0;
}

void move(int no, char x, char y)
{
    if (no > 1)
        move(no - 1, x, ('A' + 'B' + 'C') - x - y);
    printf("원반[%d]를 %c 기둥에서 %c으로 옮김\n", no, x, y);
    if (no > 1)
        move(no - 1, ('A' + 'B' + 'C') - x - y, y);
}
