#include<stdio.h>
int main()
{
    int x, i;
    printf("How many students? ");
    scanf("%d", &i);
    int age[i];
    float sum, avg;
    for(x = 0;x < i; x++)
        {
            scanf("%d",&age[x]);
            sum = sum + age[x];
        }
    avg = sum / i;
    printf("The average age is %.2f\n", avg);
    printf("Age less than the average is/are: ");
    for(x = 0; x < i; x++)
    {
        if(age[x] < avg)
            printf("%d",age[x]);
    }
    return 0;
}
