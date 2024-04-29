#include<iostream>
#include<cmath>

using namespace std;

int main(){
	int n;
	cin >> n;
	
	int eInfo[n][3];
	
	for(int i = 0; i < n; i++){
		cin >> eInfo[i][0] >> eInfo[i][1] >> eInfo[i][2];
	}
	
	int m;
	cin >> m;

	int myInfo[m][2];

	for(int i = 0; i < m; i++){
		cin >> myInfo[i][0] >> myInfo[i][1];
	}
	
	int eachResult[m][n];

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			int isUp = 0;
			int meUp = 0;
			bool isPass = 0;
			if(myInfo[i][0] < myInfo[i][1]){
				meUp = 1;
			}
			else meUp = -1;
			if(eInfo[j][1] < eInfo[j][2]){
				eUp = 1;
			}
			else eUp = -1;
			if(eUp == meUp) isPass = 1;
			if(isPass){
				if((((eInfo[j][2] - myInfo[i][0])*isUp) < 0) ^ ((eInfo[j][1] - myInfo[i][0])*isUp) > 0){
					eachResult[i][j] = abs(eInfo[j][2] - myInfo[i][1]);
				}
			}
			eachResult[i][j] = abs(eInfo[j][2] - myInfo[i][0]) + abs(myInfo[i][0] - myInfo[i][1])]
		}
	}
	for(int i = 0; i < m; i++){
		for (int j = 0; j < n)
	}
	int result[m];
}
