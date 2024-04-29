#include <stdio.h>
int main()
{
    re:{
    int a, b, c;
    printf("Enter 3 integer: ");
    scanf ("%d %d %d", &a, &b, &c);
    printf ("Sorted Output: ");
    if (a<b && a<c)
    {
        printf ("%d <= ", a);
        if (b<c)
        printf ("%d <= %d\n", b, c);
        else
        printf ("%d <= %d\n", c, b);
    }
    else if (b<a && b<c)
    {
        printf ("%d <= ", b);
        if (a<c)
        printf ("%d <= %d\n", a, c);
        else
        printf ("%d <= %d\n", c, a);
    }
    else
    {
        printf ("%d <= ", c);
        if (a<b)
        printf ("%d <= %d\n", a, b);
        else
        printf ("%d <= %d\n", b, a);
    }
    }
    goto re;
}
