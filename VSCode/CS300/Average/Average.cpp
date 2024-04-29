#include<iostream>
#include<cmath>

using namespace std;

void swap(int c[], int N){
    if(N > 1){
        for(int i = N; i > 0; i--){
            for(int j = 0; j < i - 1; j++){
                if(c[j] > c[j+1]){
                    int tmp = c[j];
                    c[j] = c[j+1];
                    c[j+1] = tmp;
                }
            }
    }
    }
}

int main(){
    int N;
    cin >> N;
    int c[N];
    for(int i = 0; i < N; i++){
        cin >> c[i];
    }
    swap(c, N);
    int p30;
    int average, sum = 0;
    if(N <= 2){
        p30 = N;
    }
    else{
        if(N*3%10 < 5){
            p30 = floor(0.3 * (float)N);
        }
        else{
            p30 = ceil(0.3 * (float)N);
        }
    }
    for(int i = 0; i < p30; i++){
            sum += c[i];
    }
    average = sum / p30;
    cout << average;
    return 0;
}