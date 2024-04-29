#include<iostream>
#include<limits>
#include <iomanip>

#define INF numeric_limits<int>::max();

using namespace std;

void line(){
    cout << endl;
    cout << "===========================================================" << endl;
    cout << endl;
}

int main(){
    int n;
    cout << "Amount of Items: ";
    cin >> n;
    int N = n+1;
    int p[N];
    for(int i{}; i < n; i++){
        cout << "Items " << (char)('A'+ i) << ": ";
        cin >> p[i] >> p[i+1]; 
    }

    line();

    for(int i{}; i < sizeof(p)/sizeof(int); i++){
        cout << 'p' << i << " = " <<  p[i] << endl;
    }

    line();

    int m[N][N];
    int s[N][N];

    for(int i = 1; i < N; i++){
        m[i][i] = 0;
    }

    for(int l = 2; l < N; l++){
        for(int i = 1; i < N-l+1; i++){
            int j = i+l-1;
            m[i][j] = INF;
            for(int k = i; k < j; k++){
                int q = m[i][k] + m[k+1][j] + (p[i-1] * p[k] * p[j]);
                if(q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << "M | ";
    for(int i = 1; i < N; i++) cout << setw(12) << i;
    cout << endl;
    for(int i{}; i < 12*n; i++){
        cout << '-';
    }

    cout << endl;

    for(int i = 1; i < N; i++){
        cout << i << " | ";
        for(int j = 1; j < N; j++){
            cout << setw(12) << m[i][j];
        }
        cout << endl;
    }

    line();

    cout << "S | ";
    for(int i = 1; i < N; i++) cout << setw(10) << i;
    cout << endl;

    for(int i = 1; i < N; i++){
        cout << i << " | ";
        for(int j = 1; j < N; j++){
            cout << setw(10) << s[i][j];
        }
        cout << endl;
    }

    line();

    return 0;
}