#include<iostream>

using namespace std;

int main(){
    int bh1, bm1, eh1, em1;
        cin >> bh1 >> bm1 >> eh1 >> em1;

    int bh2, bm2, eh2, em2;
        cin >> bh2 >> bm2 >> eh2 >> em2;

    int bh3, bm3, eh3, em3;
    bh3 = bh1 < bh2 ? bh2 : bh1;
    bm3 = bh1 < bh2 ? bm2 : bm1;
    eh3 = eh1 < eh2 ? eh1 : eh2;
    em3 = eh1 < eh2 ? em1 : em2;

    cout << bh3 << ' ';
    cout << bm3 << ' ';
    cout << eh3 << ' ';
    cout << em3 << ' ';
    
    return 0;
}