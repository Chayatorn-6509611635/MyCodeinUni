
/* Open in Project1.dev to run file */

/*
  Name: Chayatorn Prukrattananapa
  StuID: 6509611635
*/

#include <iostream>
#include <fstream>
#include "Document.h"
using namespace std;

int main(int argc, char** argv) {
	string filename;
	Document *doc = new Document();
	cout << "Enter file name: ";
	cin >> filename;
	ifstream fin(filename, ios::in);
	if(!fin){
		cerr << "Error opening the file: " << filename << endl;
		abort();
	}
	string line;
	while(!fin.eof()){
		getline(fin, line);
		doc->addSentence(line);
	}
	doc->printAll();
	
	delete doc;
	fin.close();
	return 0;
}
