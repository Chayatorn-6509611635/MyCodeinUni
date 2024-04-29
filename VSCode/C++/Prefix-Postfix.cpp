#include <iostream>

using namespace std;

int main(){
    cout << "Prefix :" << endl;
    // Prefix(++x, --x)
    int x = 1;
    int y = ++x; // x = x + 1   ->    x = y
    cout << "x is " << x << " and y is " << y << endl;

    cout << "Postfix :" << endl;
    // Postfix(a++, b--)
    x = 1;
    y = x++; // x = y   ->  x = x + 1
    cout << "x is " << x << " and y is " << y << endl;

    cout << "Compound Assignment" << endl;
    // Compound Assignment
    int a = 0, b = 0;
    a += 2; // a = a + 2
    b -= 10; // b = b + 2
    int c = 2, d = 2, e = 10;
    c *= 3; // c = c * 3
    d /= 2; // d = d / 2
    e %= 3; // e = e / 3
    cout << "a is " << a << endl;
    cout << "b is " << b << endl;
    cout << "c is " << c << endl;
    cout << "d is " << d << endl;
    cout << "e is " << e << endl;
    return 0;
    }