#include <stdio.h>

int main(){
    int num1, num2;
    printf("Please enter Num1: ");
    scanf("%d", &num1);
    printf("Please enter Num2: ");
    scanf("%d", &num2);

    int total = 0;
    for(int i = num1; i <= num2; i++){
        if(i % 6 == 0 && i % 9 == 0){
            printf("%d ", i);
            total += i;
        }
    }
    printf("\n");

    printf("Total is %d", total);
}