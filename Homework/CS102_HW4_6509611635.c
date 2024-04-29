#include<stdio.h>
int main()
{
    int n;
    printf("Please enter your ticket number: ");
    scanf("%d", &n);
    while(n>=100000)
    {
        printf("Invalid value\n");
        printf("Please enter your ticket number: ");
        scanf("%d", &n);
    }
        while(n>=10)
        {
            n = (n/10000 + n%10000/1000 + n%10000%1000/100 + n%10000%1000%100/10 + n%10000%1000%100%10);
        }
    printf("Your number is: %d\n", n);
        switch(n)
        {
            case 0:printf("Your prediction is: Bad luck");break;
            case 1:printf("Your prediction is: Good luck :)");break;
            case 2:printf("Your prediction is: Will meet your soul-mate soon^__^");break;
            case 3:printf("Your prediction is: Should make merit");break;
            case 4:printf("Your prediction is: Lucky in love");break;
            case 5:printf("Your prediction is: Need more rest!");break;
            case 6:printf("Your prediction is: Beware of an accident @_@");break;
            case 7:printf("Your prediction is: Lucky in game");break;
            case 8:printf("Your prediction is: Looking good");break;
            case 9:printf("Your prediction is: Will get some money soon");break;
        }
    return 0;
}
