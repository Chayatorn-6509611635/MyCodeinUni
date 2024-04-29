/*
  Name: Chayatorn Prukrattananapa
  StuID: 6509611635
*/
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include "Q2.h"

using namespace std;

int ** readMatrix(int size){
    if(size > 10 || size < 1) {
		cout << "Invalid size.";
		exit(0);
	}
	
	cout << "Enter " << size <<  " rows of " << size << " integers each:" << endl;
		
	int **arr = new int*[size];
    for(int i = 0; i < size; i++){
        int *subArr = new int[size];
        printf("Row %d (%d elements) : ", i, size);
        string str;
        getline(cin, str);
        stringstream input(str);
        for(int j = 0; j < size; j++){
            string num;
            input >> num;
            try{
                subArr[j] = stoi(num);
            }
            catch(const exception& e){
                subArr[j] = 0;
            }
        }
        arr[i] = subArr;
    }
    return arr;
}

int **makeSymmetricMatrix (int **matrix, int size, bool fromLower){
    int **arr = new int*[size];
    for(int i = 0; i < size; i++){
		int* subArr = new int[size];
		arr[i] = subArr;
	}
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            arr[i][j] = matrix[i][j];
        }
    }

	if(!fromLower){
        for(int i = size-1; i >= 0; i--){
            for(int j = i; j >= 0; j--){
                arr[i][j] = arr[j][i];
            }
        }
    }
    else{
        for(int i = 0; i < size; i++){
            for(int j = i; j < size; j++){
                arr[i][j] = matrix[j][i];
            }
        }
    }
    return arr;
}



void deallocate2DArr(int **arr, int size) {
    for (int i = 0; i < size; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

void printMatrix(int **matrix, int size){
	cout << endl;
	cout << "Print Matrix" << endl;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

bool isSymmetric(int **matrix, int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(matrix[i][j] != matrix[j][i]){
                return false;
            }
        }
    }
    return true;
}

int main() {
    int size;
    cout << "Enter the size of a square matrix (>=1 and <=10): ";
    cin >> size;
    fflush(stdin);
    int **oriMatrix = readMatrix(size);

    printMatrix(oriMatrix, size);
    cout << "This matrix is" 
            << (isSymmetric(oriMatrix, size) ? " " : " NOT ")
            << "symmetric.\n\n";

    int **uSymMatrix = makeSymmetricMatrix(oriMatrix, size, false);
    printMatrix(uSymMatrix, size);
    cout << "This (fromUpper) matrix is"
            << (isSymmetric(uSymMatrix, size) ? " " : " NOT ") 
            << "symmetric.\n\n";
    
    int **lSymMatrix = makeSymmetricMatrix(oriMatrix, size, true);
    printMatrix(lSymMatrix, size);
    cout << "This (fromLower) matrix is"
            << (isSymmetric(lSymMatrix, size) ? " " : " NOT ") 
            << "symmetric.\n";
    
    // deallocate memory for all created arrays
    deallocate2DArr(oriMatrix, size);
    deallocate2DArr(uSymMatrix, size);
    deallocate2DArr(lSymMatrix, size);
    return 0;
}
