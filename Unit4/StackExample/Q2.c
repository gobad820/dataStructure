

#include "IntStack.h"
#include "IntStack.c"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    // --------first Stack--------
    IntStack alpha;
    // --------second Stack--------
    IntStack beta;
    if (Initialize(&alpha, 10) == -1)
    {
        puts("ERROR");
        return -1;
    }
    int x;
    int menu;
    while (1)
    {
        printf("현재 데이터 수 : %d/%d\n", Size(&alpha, 1) + Size(&alpha, 2), Capacity(&alpha));
        printf("(1)푸시 (2)팝 (3)피크 (4)출력 (0)종료 :");
        int number;
        scanf("%d", &number);
        int x;
        int kindofStk;
        printf("Alpha or Beta?...Alpha(1) / Beta(2) :");
        scanf("%d", &kindofStk);
        if (number == 0)
            break;
        switch (number)
        {
        case 1:

            printf("데이터 : ");
            scanf("%d", &x);
            if (Push(&alpha, x, kindofStk) == -1)
            {
                puts("STACK OVERFLOW");
            }

            break;

        case 2:

            if (Pop(&alpha, &x, kindofStk) != -1)
                printf("팝 데이터는 %d입니다.\n", x);
            else
            {
                puts("STACK is Empty");
            }

            break;

        case 3:

            if (Peek(&alpha, &x, kindofStk) != -1)
                printf("피크 데이터는 %d입니다.\n", x);
            else
            {
                puts("STACK is Empty");
            }

            break;

        case 4:

            Print(&alpha, kindofStk);
            break;

        default:
            puts("숫자를 잘못 입력하였습니다.");
            break;
        }
    }

    puts("종료합니다");

    return 0;
}
