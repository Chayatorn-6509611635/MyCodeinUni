#include <iostream>
#include <sstream>

using namespace std;

int main() {
    string ip;
    cin >> ip;
    stringstream ss(ip);
    string s;
    bool c = true;
    int count = 0;

    while(getline(ss, s, '.')){
        count++;
        if(stoi(s) != 0 && s[0] == '0'){
            c = false; break;
        } else if(stoi(s) > 255){
            c = false; break;
        }
    }

    if(!c || count != 4){
        cout << "IP " << ip << " is Not Valid";
    }
    else cout << "IP " << ip << " is Valid";
    return 0;
}