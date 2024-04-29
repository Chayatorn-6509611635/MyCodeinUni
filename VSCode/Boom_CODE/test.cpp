#include<iostream>

using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    bool boo = a * !b;
    cout << b << endl;
    cout << boo;
}