#include<stdio.h>
int R(int n)
{
    if (n==0)
        return 25;
    else return R(n-1)*2;
}

int main()
{
    int i=4, j;
    j = R(i);
    printf("%d", j);
    return 0;
}
