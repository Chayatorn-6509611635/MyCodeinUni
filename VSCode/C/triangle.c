#include<stdio.h>

int main(){
    printf("Enter Lines: ");
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for (int j = n; j > i; j--){
            printf(" ");
        }
        for(int j = 0; j < i*2-1; j++){
            printf("*");
        }
        printf("\n");
    }
    for(int i = n; i >= 0; i--){
        for (int j = n; j > i; j--){
            printf(" ");
        }
        for (int j = i*2-1; j > 0; j--){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}