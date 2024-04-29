#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n], w[n];
    for(int i = 0; i < n; i++){
        cin >> a[i] >> w[i];
    }
    int suma = 0;
    int counta = 0;
    int sumw = 0;
    int countw = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == -1){continue;}
        suma += a[i];
        counta++;
    }
    for(int i = 0; i < n; i++){
        if(w[i] == -1){continue;}
        sumw += w[i];
        countw++;
    }
    for(int i = 0; i < n; i++){
        if(a[i] == -1){a[i] = suma/counta;}
        if(w[i] == -1){w[i] = sumw/countw;}
    }
    for(int i = 0; i < n; i++){
        cout << a[i] << ' ' << w[i] << endl;.
    }
    return 0;   
}