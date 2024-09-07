#include "vigenere_cipher.h"
#include <iostream>
#include <string>
#include <cctype>
#include <fstream>

using namespace std;

int charToValue(char ch) {
	if (ch == ' ') {
		return 26;
	} else {
		return toupper(ch) - 'A';
	}
}

string vigenereEncrypt(string text, string key) {
	string result;

	for(int i = 0; i < text.length(); i++) {
		int textValue, keyValue;

		textValue = charToValue(text[i]);

		keyValue = charToValue(key[i % key.length()]);

		const int encryptedValue = (textValue + keyValue) % 27;
		if (encryptedValue == 26) {
			result += ' ';
		} else {
			result += static_cast<char>('A' + encryptedValue);
		}
	}

	return result;
}

string vigenereDecrypt(string text, string key) {
	string result;

	for(int i = 0; i < text.length(); i++) {
		int textValue, keyValue;

		textValue = charToValue(text[i]);

		keyValue = charToValue(key[i % key.length()]);

		const int encryptedValue = (textValue - keyValue + 27) % 27;
		if (encryptedValue == 26) {
			result += ' ';
		} else {
			result += static_cast<char>('A' + encryptedValue);
		}
	}

	return result;
}

void vigenereTest() {
    string text = "jesuits";
    string key = "spo";
    string expected = "ATFLXGJ";

    string encryptVal = vigenereEncrypt(text, key);

    if (encryptVal != expected) {
        cout << "Vigenere encrypt test failed, output: " << encryptVal << endl;
    }
    else {
        cout << "Vigenere encrypt test passed." << endl;
    }


	string decryptVal = vigenereDecrypt(expected, key);
	
	if (decryptVal != "JESUITS") {
        cout << "Vigenere encrypt test failed, output: " << decryptVal << endl;
    }
    else {
        cout << "Vigenere encrypt test passed." << endl;
    }
}

