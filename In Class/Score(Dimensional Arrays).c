/*****************************************
Report score
40% on midterm
60%on final
Example:
    Score Report:
    ID      Midterm Final    Total
    202     20      60       44
    204     30      30       30
    205     40      50       46
    207     70      50       58
    209     90      80       84
*****************************************/
#include<stdio.h>
int main()
{
    int i,j,
        Data[5][4] = {  {202,20,60,0},
                        {204,30,30,0},
                        {205,40,50,0},
                        {207,70,50,0},
                        {209,90,80,0}   };
    for(i=0;i<5;i++)
        Data[i][3] = Data[i][1]*0.4+Data[i][2]*0.6;
    printf("ID\tMidterm\tFinal\tTotal\n");
    for(i=0;i<5;i++)
    {
        for(j=0;j<4;j++)
        printf("%d\t", Data[i][j]);
        printf("\n");
    }
}

