#include<stdio.h>

void his(long a[], long size, long res[]);

int main(){
    long a[20];
    const long size = 20;
    for(int i = 0; i < size; i++){
        scanf("%ld", &a[i]);
    }
    long res[10] = {0};
    his(a, size, res);
    for(int i = 0; i < 10; i++){
        printf("%ld\n", res[i]);
    }
    return 0;
}
/*

void his(long a[], long size, long res[]){
    for(int i = 0; i < size; i++){
        res[a[i]]++;
    }
}

*/