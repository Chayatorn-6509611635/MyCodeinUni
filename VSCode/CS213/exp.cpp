#include<iostream>
#include<stack>
using namespace std;

int main(){
    string str;
    cin >> str;
    stack<char> st;

    for(char c: str){
        if(c == '(' || c == '{' || c == '['){
            st.push(c);
        }
        else if(c == ')' || c == ']' || c == '}'){
            if(st.empty()){
                cout << "error" << endl;
                break;
            }
            else if(c == ')' && st.top() == '('){
                st.pop();
            }  
            else if(c == ']' && st.top() == '['){
                st.pop();
            }
            else if(c == '}' && st.top() == '{'){
                st.pop();
            }
            else {
                cout << "error" << endl;
                break;
            }
        }
    }
    if(!st.empty()) cout << "error" << endl;
    else cout << "yes" << endl;
}