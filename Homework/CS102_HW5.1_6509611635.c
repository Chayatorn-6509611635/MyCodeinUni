#include<stdio.h>
int main()
{
    int i,j,num[4][4],sum1 = 0,sum2 = 0;
    printf("The array 4x4:\n");
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            scanf("%d",&num[i][j]);
     for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            while(num[i][j]<0 || num[i][j]>9)
                {
                printf("It's not true(%d,%d)\n",i+1,j+1);
                printf("New number: ");
                scanf("%d",&num[i][j]);
                }
        }
    }
    for (i=0;i<4;i++)
    sum1 = sum1 + num[i][i];
    j=3;
    for(i=0;i<4;i++)
    {
        sum2 = sum2 + num[i][j];
        j-=1;
    }
    printf("The sum of first diagonal: %d\n",sum1);
    printf("The sum of second diagonal: %d\n",sum2);
    if(sum1 == sum2)
    {
        printf("It is a magic square");
    }
    else printf("It is not a magic square");
    return 0;
}
