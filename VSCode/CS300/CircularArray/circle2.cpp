#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, r, s;
    cin >> n >> r >> s;
    vector<int> x;
    int res[r];
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        x.push_back(a); 
    }
    for(int i = 0; i < r; i++){
        int m;
        cin >> m;
        m-=s;
        if(m < 0) m += n;
        int tmp = x.at(0);
        x.insert(x.begin(), x.at(n-1));
        x.pop_back();
        res[i] = x.at(m);
    }
    for(int i: res){
        cout << i << endl;
    }
    return 0;
}