#include<iostream>

using namespace std;

int main(){
    int A, X, B, Y;
    int a, b;
    if(X < 0 || A < X || X > 1000 || Y < 0 || B < Y || Y > 1000){
        cin >> A >> X;
        cin >> B >> Y;
    }
    else return -1;
    
    if(X + Y <= B){
        b = X + Y;
        a = 0;
    }
    else {
        b = B;
        a = ((X + Y) - B);
    }
    cout << a << ' ' << b;
    return 0;
}