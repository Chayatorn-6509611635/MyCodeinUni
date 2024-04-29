#include<stdio.h>

int main(){
    int x, y;
    printf("Enter size if your rectangle: ");
    scanf("%d %d", &x, &y);
    char result[x*y];
    for(int i = 0; i < x*y; i++){
        if(i%2 == 0){
            result[i] = 'O';
        }
        else{
            result[i] = 'X';
        }
        if(i != 0 && i % y == 0){
            printf("\n");
        }
        printf("%c", result[i]);
    }
    return 0;
}