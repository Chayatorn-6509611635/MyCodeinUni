#include<stdio.h>
#include<math.h>

void  swap(int *xPtr, int *yPtr)
{
    int temp;
    temp = *xPtr;
    *xPtr = *yPtr;
    *yPtr = temp;
    return 0;
}

int main()
{
    int x, y, p;
    printf("Enter X and Y: ");
    scanf("%d %d", &x, &y);
    p = pow(x, y);
    printf("X power Y is %d\n", p);
    swap(&x, &y);
    p = pow(x,y);
    printf("Y pow X is %d", p);
}
