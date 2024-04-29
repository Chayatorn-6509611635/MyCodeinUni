#include<stdio.h>

int main(){
    int x;
    int sum = 0;
    scanf("%d", &x);
    for(int i = 0; i < x; i++){
        sum+=i+1;
    }
    printf("%d", sum);
    return 0;
}
