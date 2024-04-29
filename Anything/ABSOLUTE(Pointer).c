#include<stdio.h>
void computeAbs(int x, int *abs_xPtr)
{
    if(x<0)
        *abs_xPtr = -x;
    else
        *abs_xPtr = x;
}
int main()
{
    int num, abs_num;
    printf("Enter an integer value: ");
    scanf("%d",&num);
    computeAbs(num,&abs_num);
    printf("Absolute if %d is %d",num, abs_num);
}
