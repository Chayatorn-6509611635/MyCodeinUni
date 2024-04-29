#include<iostream>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int a[], int l, int r){
    int p = a[r];
    int i = l-1;
    for(int j = l; j < r; j++){
        if(a[j] <= p){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[r]);
    return i+1;
}

void quicksort(int a[], int l, int r){
    if(l < r){
        int pivot = partition(a, l, r);
        quicksort(a, l, pivot-1);
        quicksort(a, pivot+1, r);
    }
}

int main(){
    int a[] = {3, 2, 5, 0, 1, 8, 7, 6, 9, 4};
    quicksort(a, 0, 9);
    for(int i : a){
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}