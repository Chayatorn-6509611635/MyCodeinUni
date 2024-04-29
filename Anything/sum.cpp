#include<stdio.h>
#include<limits.h>

int main(){
	int sum = 0;
	int input, dig;
	printf("Enter a number ");
	scanf("%d", &input);
	
	for(int i = 0; i < 10; i++){
		dig = input % 10;
		sum += dig;
		input /= 10;
	}
	printf("%d",sum);
}
