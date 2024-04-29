#include<iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    int S[N];
    int line[N];
    for(int i = 0; i < N; i++){  
        cin >> S[i];
        for(int j = 0; j <= S[i]; j++){
            S[i] -= j;
            line[i] = j;
        }
    }
    for(int i = 0; i < N; i++){
        cout << line[i] << ' ' << S[i] << endl;
    }
    return 0;
}