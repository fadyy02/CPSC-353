#include <iostream>
#include <string>
#include <cctype>
#include "caesar_cipher.h"
#include "util.h"
using namespace std;


char valueToChar(int value) {
    if (value == 26) {
        return ' '; // 26 maps back to space
    } else {
        return 'A' + value; // Convert character to uppercase
    }
}

// Encrypts the input text using the Caesar cipher with the given shift
string caesarEncrypt(string& text, int shift) {
    string result;

    for (int i = 0; i < text.length(); i++) {
        int charValue = charToValue(text[i]); //reads throug the text and converts 1 by 1
        int encValue = (charValue + shift) % 27; //casear encrypt for each char
        result += valueToChar(encValue);        
    }

    return result;
}

// Decrypts the input text using the Caesar cipher with the given shift
string caesarDecrypt(string& text, int shift) {
    string result;

    for (int i = 0; i < text.length(); i++) {
        int charValue = charToValue(text[i]);
        int decValue = (charValue - shift + 27) % 27; //casear decrypt for each char
        result += valueToChar(decValue);             
    }

    return result;
}
