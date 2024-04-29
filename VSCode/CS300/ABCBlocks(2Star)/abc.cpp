#include<iostream>

using namespace std;

int main(){
    int N, Mi;
    string str;

    cin >> N >> str;

    int x[N];
    for(int i = 0; i < N; i++){
        cin >> Mi;
        char c[Mi];
        for(int j = 0; j < Mi; j++){
            cin >> c[j];
        }
        bool b = false;
        for(int j = 0; j < Mi; j++){
            if(b) break;
            for(int k = 0; k < str.length(); k++){
                if(str[k] == c[j]){
                    x[i] = j+1;
                    b = true;
                    break;
                }
                else x[i] = 0;
            }
        }
    }
    for(int i = 0; i < N; i++){
        cout << x[i] << '\n';
    }
    return 0;
}