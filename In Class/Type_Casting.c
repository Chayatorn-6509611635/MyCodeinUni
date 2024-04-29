#include<stdio.h>
int main()
{
    int a, b;
    float c;
    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);
    c = (float)a / b;       //Type Casting [change integer a to float a]
    printf("c = %.2f", c);
}
