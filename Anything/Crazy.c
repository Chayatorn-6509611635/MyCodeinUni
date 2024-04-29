#include<stdio.h>

int main()
{
    int x[10] = {'X', 'a',  'p', 's'};
    int *xPtr = x;
    while (1)
    {
        printf("%c",*xPtr);
        xPtr++;
    }
    return 0;
}
