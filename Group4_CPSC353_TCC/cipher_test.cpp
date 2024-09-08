#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include "vigenere_cipher.h"
#include "caesar_cipher.h"
#include "otp_cipher.h"

using namespace std;

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


void caesarTest() {
	int shift = 3;
    string text = "HELLO WORLD";
    string expected = "KHOOR ZRUOG";

    string encValue = caesarEncrypt(text, shift);
	string decValue = caesarDecrypt(expected, shift);


    if (encValue != expected) {
        cout << "Caesar encrypt test failed, output: " << encValue << endl;
    } else {
        cout << "Caesar encrypt test passed." << endl;
    }

    if (decValue != text) {
        cout << "Caesar decrypt test failed, output: " << decValue << endl;
    } else {
        cout << "Caesar decrypt test passed." << endl;
    }
}

//create otp test
void otp_test() {
    string text = "HELLO WORLD";
}
