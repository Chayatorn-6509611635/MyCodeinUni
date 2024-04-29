#include <iostream>

using namespace std;

int main(){
    int n, k, s, m;
    cin >> n >> k >> s;

    int arr[n], res[k];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    } 

    for(int i = 0; i < k; i++){
        cin >> m;
        res[i] =  arr[(s - (i + 1) + m + n) % n]; // at start -(i + 1) to shift left to same as start 
    } //then +m to go to result and +n to turns it to positive and %n to mod
    for(int i: res){
        cout << i << endl;
    }
    return 0;
}