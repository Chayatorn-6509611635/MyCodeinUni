#include<iostream>
using namespace std;

int main(){
    int i;
    int *const p = &i;

    //*p = 6 //not ok
    i = 6; //ok
    cout << *p;
    return 0;
}