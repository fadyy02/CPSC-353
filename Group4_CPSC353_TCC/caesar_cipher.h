#ifndef CAESAR_CIPHER_H
#define CAESAR_CIPHER_H

#include <string>

using namespace std;

string caesarEncrypt(string& text, int shift);
string caesarDecrypt(string& text, int shift);

void caesarTest();

#endif // CAESAR_CIPHER_H