#include<stdio.h>
int main()
{
    int x;
    
    do {
        printf("Please enter an integer between 3-50000: ");
        scanf("%d", &x);
        printf("gogogo!!\n");
    } while(x >= 3 && x <= 50000);
    return 0;
}
