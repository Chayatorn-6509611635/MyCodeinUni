#include<iostream>

using namespace std;

int main(){
    int input,count = 0;
    cout << "Enter numbers ";
    cin >> input;
    
    while(input >= 0){
        for(int j = input; j > 0; j--){
            cout << " ";
        }
        for(int k = 0; k <= count; k++){
            cout << "*";
        }
        cout << endl;
        input--;
        count += 2;
    }
    return 0;
}