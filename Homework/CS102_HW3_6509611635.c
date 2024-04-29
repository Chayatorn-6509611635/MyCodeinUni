#include<stdio.h>
int main()
{
    int amount;
    printf("Please enter an integer between 3-50000: ");
    scanf("%d", &amount);
    while (amount < 3 || amount > 50000)
    {
        printf("Invalid Input!!\n");
        printf("Please enter an integer between 3-50000: ");
        scanf("%d", &amount);
    }
    int i,j;
    for (i=2;i<=amount;i++)
        {
            if(amount%i==0){
                printf("%d is not a prime number", amount);
                return 0;
            }
            else
                printf("%d is a prime number", amount);
                return 0;
            }
    }
