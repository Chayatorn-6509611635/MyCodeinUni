#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

int partition(int a[], int l, int r){
    int pivot = a[r];
    int j = l-1;
    for(int i = l; i < r; i++){
        if(a[i] <= pivot){
            j++;
            swap(a[i], a[j]);
        }
    }
    swap(a[r],a[j+1]);
    return j+1;
}

void quicksort(int a[], int l, int r){
    if(l < r){
        int pivot = partition(a, l, r);
        quicksort(a, l, pivot-1);
        quicksort(a, pivot+1, r);
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

    quicksort(a, 0, 19);

    for(int i = 0; i < 20; i++){
        cout << a[i];
        if(i < 19) cout << ", ";
    }
    cout << endl;
    
}