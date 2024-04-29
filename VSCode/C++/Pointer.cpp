#include<iostream>

using namespace std;

int main() {
    int number = 10;
    int *p1 = &number;
    cout << "number = " << number << endl;
    cout << "p1 = " << *p1 << endl;

    char c = 'A';
    char * p2;
    p2 = &c;
    cout << "c = " << c << endl;
    cout << "p2 = " << *p2 << endl;

    float x = 950.36;
    float* p3;
    p3 = &x; // p3 point at address of x
    *p3 = 900; // poiter of p3(value at address of x) = 900
    cout << "x = " << x << endl;
    cout << "p3 = " << *p3 << endl;
    return 0;
}