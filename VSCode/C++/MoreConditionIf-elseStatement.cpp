#include<iostream>

using namespace std;

int main() {
    int score = 85;
    if(score >= 80){
        cout << "Grade A" << endl;
    }
    else if(score >= 70){
        cout << "Grade B" << endl;
    }
    else if(score >= 60){
        cout << "Grade C" << endl;
    }
    else if(score >= 50){
        cout << "Grade D" << endl;
    }
    else {
        cout << "Grade F" << endl;
    }
    return 0;
}