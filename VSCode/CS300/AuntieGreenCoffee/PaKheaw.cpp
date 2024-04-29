#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n, s, f, result = 0;
    int s1 = 0, s2 = 0, f1 = 0, f2 = 0;
    int index = 0;
    bool do1 = 0, do2 = 0;
	cin >> n;
    for(int i = 0; i < n; i++){
		cin >> s >> f;
		index += s;
		if(i == 0){
			s1 = index;
			f1 = s1+f;
		}
		if(index >= f1){ do1 = 0; }
		if(index >= f2){ do2 = 0; }
		if(!do1 || !do2){
			if(!do1 && !do2){
				if(abs(f1 - index) >= abs(f2 - index)){
					do1 = 1;
					s1 = index;
					f1 = s1+f;
				}
				else {
					do2 = 1;
					s2 = index;
					f2 = s2+f;
				}
			}
			else if(!do1){
				do1 = 1;
				s1 = index;
				f1 = s1+f;
			}
			else if(!do2){
			 	do2 = 1;
				s2 = index;
				f2 = s2+f;
			}
		}
		else{
			if(abs(f1-index) < abs(f2-index)){
			result = abs(f1-index) > result ? abs(f1-index) : result;
				s1 = f1;
				f1 = s1+f;
			}
			else {
				result = abs(f2-index) > result ? abs(f2-index) : result;
				s2 = f2;
				f2 = s2+f;
			}
		}
	}
	cout << result;
    return 0;
}
