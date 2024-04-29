/*
LANG: C++
COMPILER: WCB
Name: Chayatorn Prukrattananapa
StdID: 6509611635
*/

#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int H[2];
    int M[2];
    cin >> H[0] >> H[1] >> M[0] >> M[1];

    int hour = (H[0]*10) + H[1];
    int min = (M[0]*10) + M[1];

    int result = abs(hour - min/5)*30;
    if(result > 180) {
        result -= 180;
    }
    cout << result << endl;
    return 0;
}