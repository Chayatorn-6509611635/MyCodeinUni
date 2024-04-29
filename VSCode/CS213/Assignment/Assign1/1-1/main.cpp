/* 
  Name: Chayatorn Prukrattananapa
  StuID: 6509611635
*/
#include<iostream>
#include<vector>

using namespace std;

vector<int> *filter(const int* arr, int size, int value, int compare){
    vector<int> *x = new vector<int>();
    for(int i = 0; i < size; i++){
        if(compare == 0){
            if(arr[i] == value){
                x->push_back(arr[i]);
            }
        }
        else if(compare > 0){
            if(arr[i] > value){
                x->push_back(arr[i]);
            }
        }
        else {
            if(arr[i] < value){
                x->push_back(arr[i]);
            }
        }
    }
    return x;
}

int main(){
    int *arr = new int[6]{11, 2, 3, 4, 5, 6};
    cout << "Original Array:\t";
    for(auto *i: arr) cout << i << ' ';
    cout << endl;
    vector<int> *is4 = filter(arr, 6, 4, 0);
    vector<int> *lo4 = filter(arr, 6, 4, -1);
    vector<int> *hi4 = filter(arr, 6, 4, 40);
    cout << "\tResult of == 4:\t";

    if(is4->empty()){cout << "NULL";}
	else
	for (int i: *is4){
        cout << i << ' ';
    }
    cout << endl;

    cout << "\tResult of < 4:\t";
    if(lo4->empty()){cout << "NULL";}
	else
		for (int i: *lo4){
            cout << i << ' ';
        }
    cout << endl;

    cout << "\tResult of > 4:\t";
    if(hi4->empty()){cout << "NULL";}
	else
	for (int i: *hi4){
        cout << i << ' ';
    }
    cout << endl << endl;
	delete arr;
	arr = new int{2, 4, 8, 10};
    cout << "Original Array:\t";
    for(int i: arr) cout << i << ' ';
    cout << endl;
    vector<int> *a = filter(arr, 4, 9, 0);
    vector<int> *b = filter(arr, 4, 10, -1);
    vector<int> *c = filter(arr, 4, 10, 1);
    
    cout << "\tResult of == 9:\t";
    if(a->empty()) {cout << "NULL";}
	else
		for (int i: *a){
            cout << i << ' ';
        }
    cout << endl;

    cout << "\tResult of < 10:\t";
    if(b->empty()) {cout << "NULL";}
    else
        for (int i: *b){
            cout << i << ' ';
        }
    cout << endl;

        cout << "\tResult of > 10:\t";
    if(c->empty()) cout << "NULL";
    else
        for (int i: *c){
            cout << i << ' ';
        }
    cout << endl;
    
    return 0;
}
