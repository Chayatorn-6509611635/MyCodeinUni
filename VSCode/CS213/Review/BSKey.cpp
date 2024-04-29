#include<iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>

using namespace std;

int search(int a[], int start, int end, int key){
    int middle = (start + end)/2;
    
    if(start > end){
        return -1;
    } else if(key > a[middle]){
       return search(a, middle +1, end, key);
    } else if(key < a[middle]){
        return search(a, start, middle-1, key);
    } else {
        return middle;
    }
}

int main(){
    srand(time(NULL));
    int a[20];
    
    
    for (int i = 0; i < 20; i++) {
        a[i] = rand() % 50 + 1;
    }

    sort(&a[0], &a[20]);
    
    for(int i = 0; i < 20; i++){
        cout << a[i];
        if(i < 19) cout << ", ";
    }
    cout << endl;

    int key = 20;

    cout << search(a, 0, 19, key);
}