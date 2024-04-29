#include<stdio.h>
int main()
    {
    int a, b, c;
    printf("Enters 3 Integers: ", a, b, c);
    scanf("%d %d %d", &a, &b, &c);
        if(a<=b && a<=c && b<=c) printf("Sorted Orders: %d <= %d <= %d\n", a, b, c);
        if(a<=b && a<=c && c<=b) printf("Sorted Orders: %d <= %d <= %d\n", a, c, b);
        if(b<=a && b<=c && a<=c) printf("Sorted Orders: %d <= %d <= %d\n", b, a, c);
        if(b<=a && b<=c && c<=a) printf("Sorted Orders: %d <= %d <= %d\n", b, c, a);
        if(c<=a && c<=b && a<=b) printf("Sorted Orders: %d <= %d <= %d\n", c, a, b);
        if(c<=a && c<=b && b<=a) printf("Sorted Orders: %d <= %d <= %d\n", c, b, a);
    }
