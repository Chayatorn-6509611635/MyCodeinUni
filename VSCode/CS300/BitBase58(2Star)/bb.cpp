#include<iostream>

using namespace std;

int convert(string address){
    int result = 0;
    for(int i = 0; i < address.length(); i++){
        if(address.at(i) >= '1' && address.at(i) <= '9'){
            result += address.at(i) - '1';
        }
        else if(address.at(i) >= 'A' && address.at(i) <= 'H'){
            result += address.at(i) - 'A' + 9;
        }
        else if(address.at(i) >= 'J' && address.at(i) <= 'N'){
            result += address.at(i) - 'J' + 17;
        }
        else if(address.at(i) >= 'P' && address.at(i) <= 'Z'){
            result += address.at(i) - 'P' + 22;
        }
        else if(address.at(i) >= 'a' && address.at(i) <= 'k'){
            result += address.at(i) - 'a' + 33;
        }
        else if(address.at(i) >= 'm' && address.at(i) <= 'z'){
            result += address.at(i) - 'm' + 44;
        }
        else result--;
    }
    return result;
}

int main(){
    string address;
    cin >> address;
    cout <<convert(address);
    return 0;
}

