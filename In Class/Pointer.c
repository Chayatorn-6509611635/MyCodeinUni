#include<stdio.h>
void swap (int* a, int* b)
{
	int z;
	 z = *a;
	*a = *b;
	*b =  z;
}
int main()
{
	int x, y;
	printf("Enter 2 integers x and y: ");
	scanf("%d %d", &x ,&y);
	printf ("x is %d, and y  is %d\n",x , y);
	swap (&x, &y);
	printf("After swapping, x is %d, and y is %d\n", x, y);
	return 0;
}
