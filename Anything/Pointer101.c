#include<stdio.h>
int main()
{
    int x = 5, y = 2;
    int *xPtr = &x;        //xPtr ชี้ไปที่ address x ()
    int *yPtr;
    yPtr = &y;              //address yPtr เหมือนกับ address y

    printf("x = %d\n",*xPtr);
    printf("y = %d\n",*yPtr);
printf("\n");
    printf("Address of x is %p\n",&x);
    printf("Address of xPtr is %p\n",xPtr);
printf("\n");
    printf("Address of y is %p\n",&y);
    printf("Address of yPtr is %p\n",yPtr);
printf("\n");
    *yPtr = 444;
    printf("Now y is %d\n",y);
    return 0;
}
