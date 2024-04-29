#include<iostream>

using namespace std;
int main() {
    int a = 2;
    int b = 1;
    bool x = (a == b);
    bool y = (a < b);
    bool z = (a >= b);

    // boolean 0(false) 1(true)
    cout << "x is " << x << endl; // false(0)
    cout << "y is " << y << endl; // false(0)
    cout << "z is " << z << endl; // true(1)
    return 0;
}