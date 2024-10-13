#include <iostream>
#include <sstream>
#include <vector>
#include <regex>
#include <map>

using namespace std;

struct score{
    map<float, int> score;
    void push_score(float score){
        this->score[score]++;
    }
};

int main(){
    string s;
    int c = -1;
    vector<vector<float>> p1;
    while(true){
        getline(cin, s);
        if(s == "\0") break;
        c++;
        string str;
        stringstream ss(s);
        regex r("[0-9]+(?:\\.[0-9]+)?");
        vector<float> a;
        while(ss >> str){
            if(regex_match(str,r)){
                a.push_back(stof(str));
            }
        }
        if(a.size() < 4) {cerr << "error at line " << c << endl; exit(0);}
        p1.push_back(a);
    }
    cout << "success" << endl;

    score sc;
    for(int i{}; i < p1.size(); i++){
        sc.push_score(p1[i][p1[i].size()-1]);
    }

    for(auto i : sc.score){
        cout << i.first << ' ' << i.second << endl;
    }
    cout << "Count: " << p1.size() << endl;
}