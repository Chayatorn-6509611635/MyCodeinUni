#include<stdio.h>
int main()
{
    int i, j, k, num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    for(i=0;i<num;i++)
    {
        for(j=num;j>i;j--)
        {
           printf(" ");
        }
        for(k=0;k<=i;k++)
        {
            printf("a");
        }
        printf("\n");
    }
    return 0;
}
