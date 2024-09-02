#include <iostream>
#include <string>
#include <cctype>
#include "caesar_cipher.h"

using namespace std;

void caesarEncrypt(string &text, int shift) {

    for(int i = 0; i< text.length(); i++){
        char &ch = text[i];

    if (isalpha(ch)){
        ch = toupper(ch); // Convert to uppercase
        ch = (ch -'A' + shift) % 27 + 'A';
    }

}
    cout << "Caesar Encrypted: " << text << 
            "(Shift: " << shift << ")" << endl;
}
//encrypted += (c - base + shift) % 26 + base;

void caesarDecrypt(string &text, int shift) {
    for(int i = 0; i< text.length(); i++){
        char &ch = text[i];

    if (isalpha(ch)){
        ch = toupper(ch); // Convert to uppercase
        ch = (ch + 'A' - shift) % 27 + 'A';
    }

}
    cout << "Caesar Decrypted: " << text << 
            "(Shift: " << shift << ")" << endl;
}