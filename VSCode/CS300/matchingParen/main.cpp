#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(){
    string str;
    cin >> str;

    string result;
    stack<char> st;
    char indexO = 'a';
    for(char c: str){
        if(c == '('){
            st.push(indexO);
            result += indexO;
            indexO++;
        }
        else if(c == ')'){
            if(st.empty()){
                result += '?';
            }
            else{
                result += st.top();
                st.pop();
            }
        }
        else {
            result += '-';
        }
    }

    while(!st.empty()){
        for(char& c: result){
            if(st.top() == c){
                c = '!';
                st.pop();
                break;
            }
        }
    }

    cout << result << endl;
    return 0;
}
