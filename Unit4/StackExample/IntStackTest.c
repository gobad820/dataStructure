/*
 * Filename: /Users/gimsanghae/Documents/DataStructure/dataStructure/Unit4/main.c
 * Path: /Users/gimsanghae/Documents/DataStructure/dataStructure/Unit4
 * Created Date: Sunday, April 19th 2020, 12:33:07 am
 * Author: 김상해
 * 
 * Copyright (c) 2020 Your Company
 */

#include "IntStack.h"
#include "IntStack.c"
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    IntStack a;
    if (Initialize(&a, 64) == -1)
    {
        printf("스택 생성에 실패했습니다");
        return 1;
    }

    while (1)
    {
        printf("현재 데이터 수 : %d/%d\n", Size(&a, 1), Capacity(&a));
        printf("(1)푸시 (2)팝 (3)피크 (4)출력 (0)종료 :");
        int number;
        scanf("%d", &number);
        int x;

        if (number == 0)
            break;
        switch (number)
        {
        case 1:
            printf("데이터 : ");
            scanf("%d", &x);
            Push(&a, x, 1);
            break;

        case 2:
            Pop(&a, &x, 1);
            printf("팝 데이터는 %d입니다.\n", x);
            break;

        case 3:
            Peek(&a, &x, 1);
            printf("피크 데이터는 %d입니다.\n", x);
            break;

        case 4:
            Print(&a, 1);
            break;

        default:
            puts("숫자를 잘못 입력하였습니다.");
            break;
        }
    }

    puts("종료합니다");
    return 0;
}
