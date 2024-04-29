
/* Open in Project1.dev to run file */

/*
  Name: Chayatorn Prukrattananapa
  StuID: 6509611635
*/

#include "Document.h"
#include "CharacterCount.h"
#include <vector>
#include <string>

Document::Document(){;
	this->arrChar = new CharacterCount[NO_CHAR];
	for (int i=0; i < 26; i++){
		arrChar[i] = CharacterCount('A'+ i);
	}
}

Document::~Document(){
	delete[] arrChar;
	this->arrChar = NULL;
}

void Document::addSentence(string str){
	doc.push_back(str);
	for(const char c : str){
 		if(Document::indexOfCharacter(c) != -1)
 		arrChar[Document::indexOfCharacter(c)].incFreq();
 	}
}

int Document::indexOfCharacter(char ch){
	if(!isalpha(ch)) return -1; // isAlpha =  Is it Alphabet? (All Lower and Upper)
	else return toupper(ch) - 'A'; // Index starts at A = 0
}

CharacterCount* Document::get(char ch){
	for(int i = 0; i < NO_CHAR; i++){
		if(toupper(arrChar[i].getLetter()) == toupper(ch)){
			return &arrChar[i];  //return pointer pointing CharacterCount in arrChar
		}
	}
	return nullptr;
}

CharacterCount* Document::maxFreq(){
	int index;
	int max = arrChar[0].getFreq();
	for(int i = 0; i < NO_CHAR; i++){
		if(arrChar[i].getFreq() > max){
			max = arrChar[i].getFreq();
			index = i;
		}
	}
	return &arrChar[index];
}

void Document::printAll(){
	cout << "Documents contains: " << doc.size() << "lines:" << endl;
	for(string str : doc){
		cout << str <<endl;
	}
	int index = 0;
	cout << "Frequency of found characters: " << endl;
		for(int i = 0; i < NO_CHAR; i++){
			if(arrChar[i].getFreq() != 0){
				cout << '\t' << arrChar[i].toString();
				index++;
			}
			else continue;
			if(index == 2){
				index = 0;
				cout << endl;
			}
		}
}

