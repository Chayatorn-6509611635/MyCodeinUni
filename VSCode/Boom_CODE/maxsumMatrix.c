#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int arr[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    int x = 0;
    int middle = n/2;
    if(n % 2 == 0){
        x = 1;
    }

    int sum[2] = {0};
    int sumdiag[2] = {0};

    for(int i = 0; i < n; i++){
        sum[0] += arr[middle][i];
        sum[0] += arr[middle-x][i];

        sum[1] += arr[i][middle];
        sum[1] += arr[i][middle-x];
        sumdiag[0] += arr[i][i];
        sumdiag[1] += arr[i][n-i-1];
    }

    int max = sum[0]/2;

    for(int i = 0; i < 2; i++){
        if(max < sum[i]/2){
            max = sum[i]/2;
        }
        if(max < sumdiag[i]){
            max = sumdiag[i];
        }
    }


    printf("%d", max);

    return 0;

}