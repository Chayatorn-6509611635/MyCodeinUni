#include<iostream>

using namespace std;

int fibonacci(int n){
    if(n < 1) return 0;
    int a, b, c;
    a = 0;
    b = 1;
    c = 0;
    for(int i = 1; i < n; i++){
        a = c;
        c = a + b;
        b = a;
    }
    return c;
}

int main(){
    for (int i = 1; i < 10; i++){
        cout << fibonacci(i) << endl;
    }
}