#include<iostream>
using namespace std;

void printArr(int *a, int size){
		cout << "Array: ";
		for (int i = 0; i < size; i++){
			cout << *(a+i) << ' ';
		}
		cout << endl;
	}

int main(int argc, char**){
	int arr[] = {1, 2, 3, 4, 5};
	int *ptr = arr;
	
	cout << *ptr << endl;
	printArr(arr, 5);
	cout << *++ptr << endl; //add address then print
	printArr(arr, 5);
	cout << ++*ptr << endl; //add value of address
	printArr(arr, 5);
	cout << *ptr++ << endl; //print first then add address
	printArr(arr, 5);
	cout << *ptr << endl;
	printArr(arr, 5);
	cout << (*ptr)++ << endl;
	printArr(arr, 5);
	
	return 0;
}
