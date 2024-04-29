#include <iostream>
#include <cmath>

using namespace std;

int getResult(int x[], int N){
    int result;
    int odd = 0;
    int even = 0;
    for(int i = 0; i < N; i++){
        if(x[i] % 2 == 0) even++;
        else odd++;
    }
    result = odd == 0 ? 0 : pow(2, even) * pow(2, odd-1);
    return result;
}

int main(){
    int N;
    cin >> N;
    int x[N];
    for(int i = 0; i < N; i++){
        cin >> x[i];
    }
    cout << getResult(x, N);
    return 0;
}