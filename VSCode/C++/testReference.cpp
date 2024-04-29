#include <iostream>

using namespace std;

int main(int argc, char **argv){
    int a = 3;
    int &b = a;
    b++;
    cout << a << ',' << b << endl;
    cout << &a << ',' << &b << endl;
    return 0;
}