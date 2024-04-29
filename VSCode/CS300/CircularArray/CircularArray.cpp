#include<iostream>

using namespace std;

int main(){
    int size;
    int round;
    int start;
    cin >> size >> round >> start;
    int arr[size];
    int newarr[size];
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }
    int result[round];
    for(int j = 0; j < round; j++){
        int m;
        cin >> m; //3-2 =1
        m -= start;
        if(m < 0){m+=size;}
        int index = 0;
        for(int i = 0; i < size; i++){
            index = i-1;
            if(index < 0) {index += size;}
            newarr[i] = arr[index];
        }
        for(int i = 0; i < size; i++){
            arr[i] = newarr[i];
            cout << newarr[i];
        }
        result[j] = newarr[m];
    }
    for(int i: result){
        cout << i << ' ';
    }
    return 0;
}