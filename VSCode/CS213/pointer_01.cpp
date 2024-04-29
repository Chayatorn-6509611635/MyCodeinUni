#include<iostream>

using std::cout;

/*
void increment(int p){
    p = p+1;
}

int main(){
    int a = 5;
    increment(a);
    cout << a;
}   
   :. result is 5
*/

void increment(int *p){
    *p = *p+1;
}

int main(){
    int a = 5;
    increment(&a);
    cout << a;
}
// :. result is 6