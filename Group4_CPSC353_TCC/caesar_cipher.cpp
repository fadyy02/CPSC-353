#include "caesar_cipher.h"
#include "util.h"
#include <string>
using namespace std;


char valueToChar(const int value) {
    if (value == 26) {
    return ' '; // 26 maps back to space
  }
  return static_cast<char>('A' + value); // Convert character to uppercase
}

// Encrypts the input text using the Caesar cipher with the given shift
string caesarEncrypt(const string & text, const int shift) {
    string result;

    for (int i = 0; i < text.length(); i++) {
      const int charValue = charToValue(text[i]); // Reads through the text and converts 1 by 1
      const int encValue = (charValue + shift) % 27; // Caesar encrypt for each char
        result += valueToChar(encValue);        
    }

    return result;
}

// Decrypts the input text using the Caesar cipher with the given shift
string caesarDecrypt(const string & text, const int shift) {
    string result;

    for (int i = 0; i < text.length(); i++) {
        int charValue = charToValue(text[i]);
        int decValue = (charValue - shift + 27) % 27; // Caesar decrypt for each char
        result += valueToChar(decValue);             
    }

    return result;
}
