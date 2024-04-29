#include<iostream>
#include<map>

using namespace std;

int main(){
    int N;
    cin >> N;
    map<int, int> type;
    int x, y;
    for(int i = 0; i < N; i++){
        cin >> x >> y;
        type[y]++;
    }
    cout << type.rbegin()->first << endl;
    cout << (++type.rbegin())->first << endl;
    return 0;
}