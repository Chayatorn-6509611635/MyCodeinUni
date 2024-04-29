#include <stdio.h>
void getMatrix(int x[][4],int y,int z)
{

    int i,j;
    for(i = 0; i < y; i++)
        for(j = 0; j < z; j++)
        scanf("%d", &x[i][j]);
}
void printMatrix(int x[][4],int y, int z)
{
    int i,j;
    for(i=0; i<y; i++)
    {
            for(j=0; j<z; j++)
            printf("%d ", x[i][j]);
        printf("\n");
    }
}
int main()
{
    int A[2][4], B[2][4], C[2][4];
    int i, j;
    printf("Enter members of 2x4 matrix A:\n");
    getMatrix(A, 2, 4);
    printf("Enter members of 2x4 matrix B:\n");
    getMatrix(B, 2, 4);
    for (i=0;i<2;i++)
        for (j=0;j<4;j++)
            C[i][j] = A[i][j] + B[i][j];
    printf("The summation matrix C is:\n");
    printMatrix(C,2,4);
    return 0;
}
