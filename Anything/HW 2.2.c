#include<stdio.h>
int main()
{
    int x, y, z;
    printf("Enter 3 integers: ");
    scanf("%d %d %d", &x, &y, &z);
    if(x<=y && x<=z)
    {
        if(y<=z) printf("Sorted output: %d <= %d <= %d\n", x, y, z);
        else printf("Sorted output: %d <= %d <= %d\n", x, z, y);
    }
    else if (y<=x && y<=z)
    {
        if(x<=z) printf("Sorted output: %d <= %d <= %d\n", y, x, z);
        else printf("Sorted output: %d <= %d <= %d\n", y, z, x);
    }
    else if (z<=x && z<=y)
    {
        if(x<=y) printf("Sorted output: %d <= %d <= %d\n", z, x, y);
        else printf("Sorted output: %d <= %d <= %d\n", z, y, x);
    }
}
