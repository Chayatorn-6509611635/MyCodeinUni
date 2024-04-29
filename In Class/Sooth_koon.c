#include<stdio.h>
int main()
{
    FILE *fptr = fopen ("multiTables2to20.txt", "w"); //2
    int i, j;
    for(i=2;i<=20;i++)
    {
        fprintf(fptr,"\"%d\"\n",i); //3
        for(j=1;j<=12;j++)
        {
            fprintf(fptr,"%d x %d = %d\n", i, j, i*j); //3
        }
        fprintf(fptr,"_______________________\n");
    }
    return 0;
}
fclose (fptr); //4.
