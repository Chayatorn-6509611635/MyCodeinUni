#include <iostream>
#include <fstream>

using namespace std;
int main() {
    ofstream myfile1;
    myfile1.open("example1.txt");    
    
    ifstream myfile2;
    myfile2.open("example2.txt");   
    
    fstream myfile3;
    myfile3.open("example3.txt");

    myfile1 << "This is the first Line" << endl;
    myfile1 << 10.5;
    myfile1.close();

    string line;
    while(getline(myfile2, line)){
        cout << line << '\n';
    }   
    myfile2.close();
    return 0;
}