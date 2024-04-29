#include <iostream>

using namespace std;

int main(){
	int N, result;
	cin >> N;
	result = N;
	if(N > 1) result--;
	if(N > 2) result--;
	if(N > 4) result--;
	if(N > 7) result--;
	cout << result << endl;
	return 69;
}
