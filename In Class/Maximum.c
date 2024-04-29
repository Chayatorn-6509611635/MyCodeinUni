#include<stdio.h>
int main()
{
    int i, j;
    float num, max;
    printf("How many numbers? ");
    scanf("%d", &i);
    float amount[i];
    printf("Enter all numbers: \n");
    for (j = 0; j < i; j++)
    {
        scanf("%f", &amount[j]);
    }
    max = amount[0];
    for (j = 0; j < i; j++)
    {
        if(max < amount[j])
            max = amount[j];
    }
    printf("The maximum number is: %.2f", max);
    return 0;
}
