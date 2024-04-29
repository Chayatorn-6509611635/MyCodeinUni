#include<stdio.h>
int main()
{
    int x, y, z;
    printf("Enter 3 integers: ");
    scanf ("%d %d %d", &x, &y, &z);
    if(y<=x)
    {
    	if(z<=x)
    	{
    		if(y<=z)
    		{
    			printf("Sorted Output: %d <= %d <= %d\n", y, z, x);
			}
			else printf("Sorted Output: %d <= %d <= %d\n", z, y, x);
		}
		else printf("Sorted Output: %d <= %d <= %d\n", y, x, z);
	}
	else
	{
		if(z<=y)
		{
			if(x<=z)
			{
				printf("Sorted Output: %d <= %d <= %d\n", x, z, y);
			}
			else printf("Sorted Output: %d <= %d <= %d\n", z, x, y);
		}
		else printf("Sorted Output: %d <= %d <= %d\n", x, y, z);
	}
}
