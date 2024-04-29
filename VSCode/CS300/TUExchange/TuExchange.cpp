/*
LANG: C++
COMPILER: WCB
*/

#include <iostream>

using namespace std;

int main(){
    float dollar;
    float exc;
    cin >> dollar;
    cin >> exc;
    float thb = dollar * exc;
    float remain = thb;
    int Thb10 = int(remain/10);
    remain -= (10*Thb10);
    int Thb5 = int(remain/5);
    remain -= (5*Thb5);
    int Thb2 = int(remain/2);
    remain -=(2*Thb2);
    int Thb1 = int(remain/1);
    remain -= (1*Thb1);
    int Thb50 = int(remain/0.5);
    remain -= (0.5*Thb50);
    int Thb25 = int(remain/0.25);
    remain -= (0.25*Thb25);
    cout << Thb10 << endl
            << Thb5 << endl
            << Thb2 << endl
            << Thb1 << endl
            << Thb50 << endl
            << Thb25 << endl;
    return 0;
}