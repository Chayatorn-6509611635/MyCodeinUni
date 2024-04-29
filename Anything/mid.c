#include<stdio.h>
int main()
{
    int x, y, z;
    float sum, avg;
    printf("Enter 3 integers: ");
    scanf("%d %d %d", &x, &y, &z);
    sum = x+y+z;
    avg = sum/3;
    printf("The average is %.2f\n", avg);
    printf("The number less than average is ");
    if(x < avg)
        printf("%d, ", x);
    if(y < avg)
        printf("%d, ", y);
    if(z < avg)
        printf("%d", z);
    return 0;
}
