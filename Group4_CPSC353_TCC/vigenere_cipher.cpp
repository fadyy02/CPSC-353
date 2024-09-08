#include "vigenere_cipher.h"
#include "util.h"
#include <iostream>
#include <string>
#include <cctype>
#include <fstream>

using namespace std;

// function to properly handle space as a 27th character
int charToValue(char ch) {
	if (ch == ' ') {
		return 26; // space maps to 26
	} else {
		return toupper(ch) - 'A'; // convert character to uppercase
	}
}

// vigenere encryption function
string vigenereEncrypt(const string &text, const string &key) {
	string result;

	// loop through to encrypt each character in the string
	for(int i = 0; i < text.length(); i++) {

          const int textValue = charToValue(text[i]);

		// mod by the key length in order to repeat through the key if shorter
          // than the input string
          const int keyValue = charToValue(key[i % key.length()]);

		// add the value of the key to the text and mod by 27 to map to a different character
		const int encryptedValue = (textValue + keyValue) % 27;
		if (encryptedValue == 26) {
			result += ' ';
		} else {
			result += static_cast<char>('A' + encryptedValue);
		}
	}

	return result;
}


// vigenere decrypt function, does the opposite of encrypt function
string vigenereDecrypt(const string &text, const string &key) {
	string result;

	// loop through to decrypt each character in the string
	for(int i = 0; i < text.length(); i++) {

          const int textValue = charToValue(text[i]);

          const int keyValue = charToValue(key[i % key.length()]);

		const int encryptedValue = (textValue - keyValue + 27) % 27;
		if (encryptedValue == 26) {
			result += ' ';
		} else {
			result += static_cast<char>('A' + encryptedValue);
		}
	}

	return result;
}



