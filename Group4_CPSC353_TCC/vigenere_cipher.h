// vigenere.h
#ifndef VIGENERE_H
#define VIGENERE_H

#include <string>

using namespace std;

string vigenereEncrypt(const string &text, const string &key);
string vigenereDecrypt(const string &text, const string &key);

void vigenereTest();

#endif
