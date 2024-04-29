#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int A[11], sum, i, *ptr;
    float avg;
    printf("The oringinal array: ");
    srand(time(NULL));
   	for(i=0;i<10;i++)
	{
        A[i] = rand() % 10 +1;
        printf( "%d ", A[i] );
    }
    printf("\n");
    for(i=0;i<10;i++)
    {
    	sum=sum+A[i];
	}
	avg = (float) sum / 10;
    printf("The  average is: %.1f\n",avg);
    ptr = A;
    for(i=10;i>4;i--)
    {
        A[i]= *(ptr+i-1);
    }
    A[5]= avg;
    printf("The current array  : ");
    for(i=0;i<11;i++)
    {
        if(i==5)
        {
            printf("%.1f ",avg); continue;
        }
        printf("%d ",A[i]);
    }
    return 0;
}
