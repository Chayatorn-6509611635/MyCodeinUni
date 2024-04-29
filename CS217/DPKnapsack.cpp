#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

void line(){
    cout << endl;
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << endl;
}

int main(){
    int n;
    cout << "Amount of items: ";
    cin >> n;
    int N = n+1;

    int W;
    cout << "Target weight: ";
    cin >> W;

    int C = W+1;

    int weights[n];
    int values[n];
    for(int i{}; i < n; i++){
        cout << "Item " << i+1 << "(v, w): ";
        cin >> values[i] >> weights[i];
    }

    line();

    for(int i = 0; i < n; i++){
        cout << "Item " << i+1 << ": ";
        cout << values[i] << " " << weights[i] << endl;
    }

    line();

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "V | ";
    for(int i{}; i < C; i++){
        cout << setw(10) << i;
    }
    cout << endl;
    cout << "-------------------------------------------------" << endl;
    for(int i{}; i < N; i++){
        cout << i << " | ";
        for(int j{}; j < C; j++){
            cout << setw(10) << dp[i][j];
        }
        cout << endl;
    }
    
    line();

    return 0;
}