#include<iostream>
#include<sstream>
#include<regex>

using namespace std;

int main(){
    string str;
    getline(cin, str);
    regex_replace(str.begin(), str.begin(), str.end(), regex("[0-9]"), " ");
    string fname, sname;
    stringstream ss(str);
    ss >> fname >> sname;

    char gen;
    cin >> gen;
    cout << "Hello " << (gen == 'M' ? "Mr. " : "Mrs. ") << sname << ", " << fname << endl;
    return 0;
}