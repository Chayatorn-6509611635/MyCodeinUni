#include<iostream>

using namespace std;

;

void  merge(int a[], int left, int middle, int right){
    int i, j, k, aux[right-left+1];
    for(i = middle+1; i > left; i--){ //copy from left to middle
        aux[i-1] = a[i-1];
    }
    for(j = middle; j < right; j++){
        aux[middle+right-j] = a[j+1]; //copy from right to middle+1 (reversed)
    }
    for(k = left; k < right; k++){
        if(aux[i] < aux[j]){
            a[k] = aux[i++]; //assign then slide to next index
        }
        else{
            a[k] = aux[j--];
        }
    }
}

void mergesort (int a[], int left, int right){
    if(left < right){
        int middle = (left + right)/2;

        mergesort(a, left, middle);
        mergesort(a, middle+1, right);
        merge(a, left, middle, right);
    }
}

int main(){
    int a[10] = {9, 10, 75, 2, 64, 3, 8, 6, 4};
  
    mergesort(a, 0, 9);
    for(int i = 0; i < 9; i++){
        cout << a[i] << ' ';
    }
    cout << endl;
}