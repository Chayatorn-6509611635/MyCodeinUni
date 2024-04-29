#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    int type[6] = {0};
    int x, y;
    for(int i = 0; i < N; i++){
        cin >> x >> y;
        switch(y){
            case 1: type[0]++; break;
            case 2: type[1]++; break;
            case 3: type[2]++; break;
            case 4: type[3]++; break;
            case 5: type[4]++; break;
            case 6: type[5]++; break;
        }
    }
    int max = type[0];
    int index1 = 0;
    for(int i = 0; i < 6; i++){
        if(max < type[i]){
            index1 = i;
            max = type[i];
        }
    }
    max = type[0];
    type[index1] = -1;
    int index2 = 0;
    for(int i = 0; i < 6; i++){
        if(max < type[i]){
            index2 = i;
            max = type[i];
        }
    }

    cout << index1+1 << endl
            << index2+1 << endl;
    return 0;
}