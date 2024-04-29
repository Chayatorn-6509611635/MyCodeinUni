#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;  
}

void merge(int a[], int l, int middle, int r){
    int i = l, j = middle+1, k = 0;
    int aux[r - l + 1];

    while(i <= middle && j <= r){
        if(a[i] <= a[j]) aux[k++] = a[i++];

        else aux[k++] = a[j++];
    }

    while(i <= middle) aux[k++] = a[i++];
    while(j <= r) aux[k++] = a[j++];

    for(int i = 0; i < k; i++)
        a[i+l] = aux[i];
}

void mergesort(int a[], int l, int r){
    if(l < r){
        int middle = (l + r) / 2;
        mergesort(a, l, middle);
        mergesort(a, middle+1, r);
        merge(a, l, middle, r);
    }
}

int main(){
    srand(time(NULL));
    int a[20];
    
    
    for (int i = 0; i < 20; i++) {
        a[i] = rand() % 50 + 1;
    }

    for(int i = 0; i < 20; i++){
        cout << a[i];
        if(i < 19) cout << ", ";
    }
    cout << endl;

    mergesort(a, 0, 19);

    for(int i = 0; i < 20; i++){
        cout << a[i];
        if(i < 19) cout << ", ";
    }
    cout << endl;
    
}