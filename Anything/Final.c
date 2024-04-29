#include<stdio.h>

void One(int;& A, int B, int ;&C){
    const int D=1;
    A--; B=15;D=D+3;
    printf("after One : %d %d %d %d", A, B, C, D);
}

int main(){
    int A=5,B=5,C=5,D=5;
    printf("%d %d %d %d", A, B, C, D);
    One(A,B,C);
    printf("in main : %d %d %d %d", A, B, C, D);
}
