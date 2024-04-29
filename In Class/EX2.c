#include <stdio.h>
int main()
{
	int money;
	printf("Enter your withdrawal amount: ");
	scanf("%d", &money);
	if(money%100 > 0){
		printf("You can't withdraw with this");
	}
	else{
	printf("#1000-bank notes: %d\n",money/1000);
	printf("# 500-bank notes: %d\n",(money%1000)/500);
	printf("# 100-bank notes: %d\n",((money%1000)%500)/100);
	return 0;
	}
}
