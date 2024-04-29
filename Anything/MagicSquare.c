#include<stdio.h>
int MagicSquare(int Horizon[],int Verticle[],int Diag1,int Diag2,int size)
{
    int T = 0, F = 1;
    for(int i=0;i<size;i++)
        for(int j=0;j<size;j++)
        {
            if (Horizon[i]!=Verticle[j])
            F = -1;
        }
    if (F == -1) return F;
    else if(Verticle[0]!=Diag1) return F;
    else if(Diag1!=Diag2) return F;
    else return T;
}
int main()
{
    int i, j, k, n;
    printf("Enter size of square: ");
    scanf("%d", &n);
    int A[n][n], sumH[n], sumV[n], sumX1=0, sumX2=0;
    printf("Enter number in the square %dx%d\n",n ,n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        scanf("%d", &A[i][j]);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            while(A[i][j] < 0 || A[i][j] > 9)
            {
                printf("(%d,%d) is not 0-9, please enter valid number: ", i+1, j+1);
                scanf("%d",&A[i][j]);
            }
    }
    for(i=0;i<n;i++)
    {
        sumX1 += A[i][i];   //SumX1
    }
    j=n-1;
    for(i=0;i<n;i++)
    {
        sumX2 += A[i][j];   //SumX2
        j--;
    }
    for(k=0;k<n;k++)
    {
        sumV[k]=0;          //SumV
        for(i=0;i<n;i++)
            sumV[k] += A[i][k];
    }
    for(k=0;k<n;k++)
    {
        sumH[k]=0;          //SumH
        for(j=0;j<n;j++)
            sumH[k] += A[k][j];
    }
    printf("The First sum of diagonal: %d\n", sumX1);
    printf("The Second sum of diagonal: %d\n", sumX2);
    for(i=0;i<n;i++)
        printf("Sum of the %d verticle: %d\n",i+1,sumV[i]);
    for(i=0;i<n;i++)
        printf("Sum of the %d verticle: %d\n",i+1,sumH[i]);
    int m = MagicSquare(sumH,sumV,sumX1,sumX2,n);
    if(m ==  0) printf("This is a magic square.");
    if(m == -1) printf("This is not a magic square.");
    return 0;
}
