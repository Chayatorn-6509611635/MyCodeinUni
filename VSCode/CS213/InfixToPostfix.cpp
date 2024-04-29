#include<iostream>
#include<stack>

using namespace std;

bool isTrue(char a, char b){
    int na, nb;
    switch(a){
        case '+':   case '-':
            na = 1; break;
        case '*':   case '/':   case '%':
            na = 2; break;
    }
    switch(b){
        case '+':   case '-':
            nb = 1; break;
        case '*':   case '/':   case '%':
            nb = 2; break;
    }
    return na <= nb;
}

int main(){
    string str;
    cin >> str;
    stack<char> st;
    string out;

    for(char c: str){
        if(c >= 'a' && c <= 'z'){
            out += c;
        }
        else if(c == '('){
            st.push(c);
        }
        else if(c == ')'){
            while(st.top() != '('){
                out += st.top();
                st.pop();
            }
            st.pop();
        }
        else if(c == '+' || c == '-' || c == '*' || c == '%' || c == '/'){
            while(!st.empty() && st.top() != '(' && (isTrue(c, st.top()))){
                out += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()){
        out += st.top();
        st.pop();
    }

    cout << out << endl;
    return 0;
}