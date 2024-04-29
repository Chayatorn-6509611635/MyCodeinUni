#include<iostream>
#include<string.h>
#include "StuStruct.h"

using namespace std;

int main(){
    StudentRecord s1, s2;
    s1.name = new char[sizeof("John Smith")];
    strcpy(s1.name, "John Smith");
    s1.hw[0] = 10;

    s2 = s1; //copy s1 to s2
    cout << s1.name << " score " << s1.hw[0] << endl;
    cout << s2.name << " score " << s2.hw[0] << endl;
    
    s2.hw[0] = 8;
    strcpy(s2.name, "Jane Doe");
    cout << s1.name << " score " << s1.hw[0] << endl;
    cout << s2.name << " score " << s2.hw[0] << endl;

    return 0;
}