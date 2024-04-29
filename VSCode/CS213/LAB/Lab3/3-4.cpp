#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
using namespace std;
int main(int argc, char** argv){
	string filename = "my_activities.txt";
	ofstream fout(filename.c_str(), ios::out);
	if(!fout){
		cerr << "Error: open file for output failed!" << endl;
		abort();
	}
	for(int i = 0; i < 3; i++){
		string line;
		getline(cin, line);
		fout << line << endl;
	}
	fout.close();
	return 0;
}
