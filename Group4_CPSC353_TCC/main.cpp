/*
Team Members: Fady Youssef, 
              Tyler Montague,
              Caedyn Reece,
              Steve Deibert
Course: CPSC 353
Date Submitted: 09/08/2024
Assignment Name: Three Classical Ciphers
Description Program implements the 
*/
#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include "caesar_cipher.h"
#include "otp_cipher.h"
#include "vigenere_cipher.h"
#include "util.h"

using namespace std;

void choose_options(int &mode, int &cipher) {
    while (true) {
        cout << "Enter mode (1: Encrypt, 2: Decrypt): ";
        cin >> mode;
        if (mode == 1 || mode == 2) {
            break;
        }
        cout << "Invalid mode. Please enter 1 or 2." << endl;
    }

    while (true) {
        cout << "Enter cipher (Caesar: 1, Vigenere: 2, OTP: 3): ";
        cin >> cipher;
        if (cipher == 1 || cipher == 2 || cipher == 3) {
            break;
        }
        cout << "Invalid cipher. Please enter 1, 2, or 3." << endl;
    }
}

void process_cipher(int mode, int cipher) {
    string input, output, key;
    int shift;

    cout << "Enter input text: ";
    cin.ignore(); // Ignore newline character left in buffer
    getline(cin, input);
    for (auto &c : input) c = static_cast<char>(toupper(c)); // Convert input to uppercase

    if (cipher == 1) { // Caesar Cipher
        cout << "Enter shift key (number): ";
        cin >> shift;
        if (mode == 1) {
            output = caesarEncrypt(input, shift);
        } else {
            output = caesarDecrypt(input, shift);
        }
    } else if (cipher == 2) { // Vigenere Cipher
        cout << "Enter key: ";
        cin >> key;
        for (auto &c : key) c = static_cast<char>(toupper(c)); // Convert key to uppercase
        if (mode == 1) {
            output = vigenereEncrypt(input, key);
        } else {
            output = vigenereDecrypt(input, key);
        }
    } else if (cipher == 3) { // OTP Cipher
        if (mode == 1) {
            key = generateRandomKey(static_cast<int>(input.length()));
            output = otpEncrypt(input, key);
        } else {
            cout << "Enter key: ";
            cin >> key;
            for (auto &c : key) c = static_cast<char>(toupper(c)); // Convert key to uppercase
            output = otpDecrypt(input, key);
        }
    }

    cout << "Output: " << output << endl;
	// Save cipher output to file
    ofstream cipherFile("ciphertext.txt");
    cout << "Cipher saved to file: ciphertext.txt" <<endl;
    cipherFile << output;
    cipherFile.close();
	// Save cipher key to file
    if (cipher != 1) {
        ofstream keyFile("key_text.txt");
        cout << "Key saved to file: key_text.txt" <<endl;
        keyFile << key;
        keyFile.close();
    } else {
        ofstream keyFile("shift_text.txt");
        cout << "Shift saved to file: shift_text.txt" <<endl;
        keyFile << shift;
        keyFile.close();
    }
}

int main() {
    int mode, cipher;
	char repeat;
    testCiphers();

    while (true) {
        choose_options(mode, cipher);
        process_cipher(mode, cipher);

        cout << "Do you want to perform another operation? (y/n): ";
        cin >> repeat;
        if (tolower(repeat) != 'y') {
            break;
        }
    }

    return 0;
}