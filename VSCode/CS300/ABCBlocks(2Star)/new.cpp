#include <iostream>

using namespace std;

int main(){
    int N;
    string str;
    cin >> N ;
    cin >> str;
    int size = str.size();
    int result[N] = {0};
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        bool check = 0;
        char ch[x];
        for(int j = 0; j < x; j++) {cin >> ch[j];}
        for(int j = 0; j < x; j++){
            for(int k = 0; k < size; k++){
                if(ch[j] == str[k]){
                    result[i] = j+1;
                    check = true;
                    break;
                }
            }
            if(check) {break;}
        }
    }
    for(int i = 0; i < N; i++){
        cout << result[i] << endl;
    }
    return 0;
}