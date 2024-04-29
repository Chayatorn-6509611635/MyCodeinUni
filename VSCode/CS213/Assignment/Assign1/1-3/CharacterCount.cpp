
/* Open in Project1.dev to run file */

/*
  Name: Chayatorn Prukrattananapa
  StuID: 6509611635
*/

#include "CharacterCount.h"
#include <sstream>
#include <cctype>

CharacterCount::CharacterCount(char letter)
    : letter(tolower(letter)), freq(0) {}

void CharacterCount::setLetter(char ch) { this->letter = toupper(ch); }

char CharacterCount::getLetter() { return this->letter; }

int CharacterCount::getFreq() { return this->freq; }

void CharacterCount::incFreq() { this->freq++; }

void CharacterCount::addFreq(int count) { this->freq += count; }

string CharacterCount::toString() {
    bool x = this->letter == toupper(this->letter);
    stringstream out;
    char ch = toupper(this->letter);
    out << ch << " Freq: " << this->freq;
    string result = out.str();
    return result;
}

