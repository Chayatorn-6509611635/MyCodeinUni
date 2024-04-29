#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int num = 0;
    float x, X;
    string str;
    bool tf = 1;
    char c = 'a';
    double doub = 5.78;
    int radius = 7;

    //constant == final(in java)
    const double PI = 3.14;

    x = 2;
    X = ++x;

    cout << "num = " << num << endl;
    cout << "x is " << x << " and X is " << X << endl;
    cout << "Circle area is " << PI * pow(radius, 2) << endl;
    cout << "bool is " << (tf == 0 ? "false" : "true") << endl;
    cout << "char is " << c;
    cout << "double is " << doub << endl;
    return 0;
}