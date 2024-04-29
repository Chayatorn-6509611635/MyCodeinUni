#include<stdio.h>
//Calculate the sum of the matrix A and matrix B
//that has a size of 2x3.
int main()
{
    int i, j;
    float A[2][3], B[2][3], C[2][3];
    printf("Enter numbers for 2x3 matrix A:\n");
    for (i=0;i<2;i++)
        for (j=0;j<3;j++)
            scanf ("%f", &A[i][j]);
    printf("Enter numbers for 2x3 matrix B:\n");
    for (i=0;i<2;i++)
        for (j=0;j<3;j++)
            scanf ("%f", &B[i][j]);
    for (i=0;i<2;i++)
        for (j=0;j<3;j++)
            C[i][j] = A[i][j] + B[i][j];
    printf("The summation matrix C is:\n");
        for (i=0;i<2;i++)
        {
            for (j=0;j<3;j++)
                printf("%.1f\t", C[i][j]);
            printf("\n");
        }
            return 0;
}
