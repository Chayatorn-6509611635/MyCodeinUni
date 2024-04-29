/* student ID : 6509611916
   Name : Pornnapas Metwattarakul */
#include<stdio.h>
float findTax (char Type, int cost){
	float tax;
	if(Type == 'A')
	tax = 0.1*cost;
	else if(Type == 'B')
	tax = 0.15*cost;
	else if(Type == 'C')
	tax = 0.2*cost;
	else if(Type == 'D')
	tax = 0.4*cost;
	return tax;
}

	struct myGoodsRec {
		int ID;
		char name[20];
		char type;
		float cost;
		float tax;
		float netPrice;
	};
	typedef struct myGoodsRec Goods;
	Goods myGoods[100];
int main(){
	int i;
	FILE * fp = fopen("Goods.txt", "r");
	FILE * FP = fopen("Report6509611916.txt", "w");

	if (fp == NULL || FP == NULL)
	{
		printf("ERROR : FILE CANNOT OPEN");
		return -1;
	}

	fprintf(FP, "ID\t\tName\t\t\tType\t\tCost\t\tTax\t\tNetPrice\n");

	for(i=0;i<12;i++)
	{ fscanf(fp, "%i %s %c %f", &myGoods[i].ID, myGoods[i].name, &myGoods[i].type, &myGoods[i].cost);}

	for(i=0;i<12;i++){
		myGoods[i].tax = findTax(myGoods[i].type, myGoods[i].cost);
		myGoods[i].netPrice = myGoods[i].cost + myGoods[i].tax;
	}
	for(i=0;i<12;i++)
	{
		fprintf(FP, "%i\t\t%-20s%c\t\t %.2f\t %.2f\t %.2f\n", myGoods[i].ID, myGoods[i].name, myGoods[i].type, myGoods[i].cost, myGoods[i].tax, myGoods[i].netPrice);
	}

	fclose(fp);
	fclose(FP);

	return 0;

}
