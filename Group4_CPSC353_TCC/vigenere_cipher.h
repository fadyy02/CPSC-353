// vigenere.h
#ifndef VIGENERE_H
#define VIGENERE_H

#include <string>

using namespace std;

int charToValue(char ch);
string vigenereEncrypt(string text, string key);
string vigenereDecrypt(string text, string key);

void vigenereTest();

#endif
