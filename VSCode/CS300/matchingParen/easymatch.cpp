#include<iostream>
#include<stack>

using namespace std;

int main(){
    string str;
    cin >> str;

    stack<char> st;
    bool check = 1;
    
    for(char c: str){
        if((c == '(') || (c == '[') || (c == '{')){
            st.push(c);
        }

        else if((c == ')') && (!st.empty()) && (st.top() == '(')){
        st.pop();
        }
        else if((c == ']') && (!st.empty()) && (st.top() == '[')){
            st.pop();
        }
        else if((c == '}') && (!st.empty()) && (st.top() == '{')){
            st.pop();
        }
        else {
            check = 0;
            break;
        }
    }

    if(!st.empty()){
        check = 0;
    }

    cout << (check == 0 ? "false" : "true") << endl;
    
    return 0;
}