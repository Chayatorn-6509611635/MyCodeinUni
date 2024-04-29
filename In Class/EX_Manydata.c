#include<stdio.h>
int main()
{
    int num, age, i;
    float sum,avg;
    printf("How many students?: ");
    scanf("%d", &num);
    sum = 0;
    printf("Enter ages: \n");
    for (i=1;i<=num;i++)
    {
        scanf("%d", &age);
        sum = sum + age;
    }
    avg = sum/num;
    printf("The average age is %.2f years.\n", avg);
}

