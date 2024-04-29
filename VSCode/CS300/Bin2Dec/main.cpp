#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int n;
    cin >> n;
    int res = 0;
    int x;
    for(int i = 0; i < n; i++){
        cin >> x;
        res += (x * pow(2, n-1-i));
    }
    cout << res;
    return 0;
}