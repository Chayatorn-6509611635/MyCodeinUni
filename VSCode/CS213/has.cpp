#include <iostream>

using namespace std;

int h ( char *k, int n ) {   int sum = 0;   while( --n ) sum = sum + *k++;   return sum%13;}

int main(){
    char s[] = {'A','n','a','c','o', 'n', 'd', 'a'};
    cout << h(s, 9);
    return 0;
}