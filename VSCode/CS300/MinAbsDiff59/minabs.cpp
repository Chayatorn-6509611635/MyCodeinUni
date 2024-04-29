#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    int num[n] = {0};
for(int i = 0; i < n; i++){
    cin >> num[i];
}
    int min;
    vector<int> result;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(j >= n) continue;
            result.push_back(abs(num[i] - num[j]));
        }
    }

    cout << *min_element(result.begin(), result.end()) << endl;

    return 0;
}