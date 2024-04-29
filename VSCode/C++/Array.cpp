#include<iostream>

using namespace std;

int main() {
    int a[] = {1, 2, 3, 4};

    cout << a[0] << endl; // first element starts at 0
    cout << a[3] << endl; // least element ends at n-1
    cout << a[4] << endl; // index out of bound
    return 0;
}