#include<iostream>
#include<set>

using namespace std;

int main(){
    int N, M, f, l;
    cin >> N >> M;

    set<int> s;

    for(int i = 0; i < M; i++){
        cin >> f >> l;
        for(int j = f; j <= l; j++){
            s.insert(j);
        }
    }
    cout << s.size() << '\n';
    return 0;
    }