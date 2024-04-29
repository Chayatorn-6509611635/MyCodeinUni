#include<stdio.h>
#include<math.h>
 float average(int n[],int i)
 {
     int sum = 0;
     float avg;
     for(int x=0 ; x<i ; x++)
        sum += n[x];
        printf("%d\n", sum);
     avg = 1.0*sum/i;
     return avg;
 }
 int main()
 {
     int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
     int i, j, k, sum1=0;
     float avg, sumSD, SD;
     avg = average(A, 10);
    printf("%d", sumSD);
 }
