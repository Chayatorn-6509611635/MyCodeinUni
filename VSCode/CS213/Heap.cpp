#include<iostream>

using std::cout;

int x = 5;
int y = 10;

void func(){}

int main(){
    int i = 20;
    int *p;

    p = new int;
    *p = 50;

    cout << *p;

    delete(p);

    cout << *p;

    return 0;
}