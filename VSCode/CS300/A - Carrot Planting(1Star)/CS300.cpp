#include<iostream>

using namespace std;

int main(){
    int N, M, b, e, count = 0;
    cin >> N >> M;
    if(N > 100 || N < 1 || M > 100 || M < 1) return -1;
    bool a[N];
    for(int i = 0; i < M; i++){
        cin >> b >> e;
        for(int j = b; j <= e; j++){
            a[j] = 1;
        }
    }
    for(int i = 0; i < N; i++){
        if(a[i] == 1) count++;
    }
    cout << count;
    return 0;
}