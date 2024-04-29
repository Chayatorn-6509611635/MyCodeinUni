#include<stdio.h>
int main ()
{
    float area;
    int w,h;
    printf("Enter width ");
    scanf("%d",&w);
    printf("Enter height ");
    scanf("%d",&h);
    area = .5*h*w;
    printf("The area is %f\n", area);
    return 0;
}
