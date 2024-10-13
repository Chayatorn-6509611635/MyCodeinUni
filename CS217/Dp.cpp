#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int g, n;
    cin >> g >> n;
    int w[n];
    for(int i{}; i < n; i++){
        cin >> w[i];
    }
    sort(w,w+n);
    int c = 0;
    for(int i: w){
        if(g-i >= 0){
            g-=i;
            c++;
        }
    }
    cout << c << endl;
}