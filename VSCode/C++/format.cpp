#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    float x = 122;
    cout  << setprecision(2) << setw(6) << setfill('0') << x << endl;
}