#include<stdio.h>
typedef struct myGoodsRec   //define new
{
    int ID;
    char name[20];
    char type;
    float cost;
    float tax;
    float netPrice;
}  Goods;
Goods myGoods [100];    //array of goods

float findtax(float, char);

int main()
{
    FILE *fptrI = fopen("Goods.txt","r"), *fptrO = fopen("Report6509611635.txt","w");
    if(fptrI == NULL || fptrO == NULL)
    {
        printf("Error to open file.");
        return -1;
    }
    fprintf(fptrO,"ID\tName\t\t\tType\t\tCost\t\tTax\t\tNetprice\n");
    int i = 0;
    while(fscanf(fptrI,"%d %s %c %f", &(myGoods[i].ID), (myGoods[i].name), &(myGoods[i].type), &(myGoods[i].cost)) == 4)
    {
        myGoods[i].tax = findtax(myGoods[i].cost, myGoods[i].type);
        myGoods[i].netPrice = myGoods[i].cost + myGoods[i].tax;
        fprintf(fptrO,"%d\t%-15s\t%-8c%8.2f\t%9.2f\t%14.2f\n",myGoods[i].ID,myGoods[i].name,myGoods[i].type,myGoods[i].cost,myGoods[i].tax,myGoods[i].netPrice);
        i++;
    }
    fclose(fptrI);
    fclose(fptrO);
    return 0;
}

float findtax(float n, char ch)
{
    switch (ch)
    {
    case 'A': n = 0.1*n; break;
    case 'B': n = 0.15*n; break;
    case 'C': n = 0.2*n; break;
    case 'D': n = 0.4*n; break;
    }
    return n;
}
