#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include "vigenere_cipher.h"
#include "caesar_cipher.h"
#include "otp_cipher.h"

using namespace std;

// test vigenere encrypt and decrypt using a known string (from assesment 1)
void vigenereTest() {
    string text = "jesuits";
    string key = "spo";
    string expected = "ATFLXGJ";

    string encryptVal = vigenereEncrypt(text, key);

    // if it fails either encrypt or decrypt an error message is displayed
    if (encryptVal != expected) {
        cout << "Vigenere encrypt test failed, output: " << encryptVal << endl;
    }

	string decryptVal = vigenereDecrypt(expected, key);
	
	if (decryptVal != "JESUITS") {
        cout << "Vigenere encrypt test failed, output: " << decryptVal << endl;
    }
}


void caesarTest() {
	int shift = 3;
    string text = "HELLO WORLD";
    string expected = "KHOORCZRUOG";

    string encValue = caesarEncrypt(text, shift);
	string decValue = caesarDecrypt(expected, shift);


    if (encValue != expected) {
        cout << "Caesar encrypt test failed, output: " << encValue << endl;
    } 

    if (decValue != text) {
        cout << "Caesar decrypt test failed, output: " << decValue << endl;
    } 
}

//create otp test
void otp_test() {
    string text = "HELLO WORLD";
}
