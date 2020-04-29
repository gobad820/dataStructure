
#include <stdio.h>
#include <stdlib.h>
#include "deck.h"
#include "deck.c"
int main(int argc, char const *argv[])
{
    Deck alpha;
    if ((Initialize(&alpha, 5)) == -1)
    {
        puts("ERROR");
        return 0;
    }
    int menu;
    int x;
    int bot;
    while (1)
    {
        puts("Enqueue...1 / Dequeue...2 / Peek...3 / Clear...4 / Capacity...5 / Size...6 / IsEmpty...7 / IsFull...8 / Search...9 / Print...10 / Terminate...11");
        scanf("%d", &menu);
        if (menu == 0)
            break;
        switch (menu)
        {
        case 1:
            printf("DATA , Bottom : ");
            scanf("%d %d", &x, &bot);
            if (Enqueue(&alpha, x, bot) != -1)
            {
                printf("Enqueue %d\n", x);
            }
            else
            {
                puts("THE QUEUE IS FULL");
            }
            break;
        case 2:
            printf("Bottom : ");
            scanf("%d", &bot);
            if (Dequeue(&alpha, &x, bot) != -1)
            {
                printf("The Number Dequeued : %d\n", x);
            }
            else
            {
                puts("The Queue is Empty");
            }
            break;
        case 3:
            printf("Bottom : ");
            scanf("%d", &bot);
            if (Peek(&alpha, &x, bot) != -1)
            {
                printf("The Front Number : %d\n", x);
            }
            else
            {
                puts("The Queue is Empty");
            }
            break;
        case 4:
            Clear(&alpha);
            puts("Clear Complete");
            break;
        case 5:
            Capacity(&alpha);
            break;
        case 6:
            if (Size(&alpha) == -1)
            {
                puts("The Queue is not Empty");
            }
            else
            {
                puts("The Queue is Empty");
            }
            break;
        case 7:
            if (IsEmpty(&alpha) == -1)
            {
                puts("The Queue is Not Empty");
            }
            else
            {
                puts("The Queue is Empty");
            }

        case 8:
            if (IsFull(&alpha) == -1)
            {
                puts("The Queue is Not Full");
            }
            else
            {
                puts("The Queue is Full");
            }
            break;
        case 9:
            printf("Key : ");
            scanf("%d", &x);
            if (Search(&alpha, x) == -1)
                puts("The Key is Not Exist");
            break;
        case 10:
            Print(&alpha);
            break;
        case 11:
            Terminate(&alpha);
            break;
        default:
            puts("You Enter Wront Number");
            break;
        }
    }
    return 0;
}
