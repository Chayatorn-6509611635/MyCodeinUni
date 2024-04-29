#include <stdio.h>

int main(){
    int budget;
    printf("Please enter a budget amount: ");
    scanf("%d", &budget);

    printf("We can provide support for %d students.\n", budget / 599 * 4);
    printf("The amount of budget remains %d bahts.\n", budget % 599);
    return 0;
}