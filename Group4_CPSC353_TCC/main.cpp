/*
Team Members: Fady Youssef, 
              Tyler Montague,
              Caedyn Reece,
              Steve Deibert
Course: CPSC 353
Date Submitted: 09/0/2024
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

using namespace std;

int main() {
	int mode;
	string input, output, cipher, key;

	while (true) {
		cout << "Enter mode (1: encrypt, 2: decrypt): ";
		cin >> mode;
		if (mode != 1 && mode != 2) {
			cout << "Invalid mode. Please enter 1 or 2." << endl;
			continue;
		}

		cout << "Enter cipher (caesar, vigenere, otp): ";
		cin >> cipher;
		for (auto &c : cipher) c = toupper(c);  // Convert to uppercase

		cout << "Enter input text: ";
		cin.ignore();  // Ignore newline character left in buffer
		getline(cin, input);
		for (auto &c : input) c = toupper(c);  // Convert input to uppercase

		if (cipher == "CAESAR") {
			int shift;
			cout << "Enter shift key (number): ";
			cin >> shift;
			if (mode == 1) {
				output = caesarEncrypt(input, shift);
			} else {
				output = caesarDecrypt(input, shift);
			}
		} else if (cipher == "VIGENERE") {
			cout << "Enter key: ";
			cin >> key;
			for (auto &c : key) c = toupper(c);  // Convert key to uppercase
			if (mode == 1) {
				output = vigenereEncrypt(input, key);
			} else {
				output = vigenereDecrypt(input, key);
			}
		} else if (cipher == "OTP") {
			cout << "Enter key: ";
			cin >> key;
			for (auto &c : key) c = toupper(c);  // Convert key to uppercase
			if (mode == 1) {
				output = otpEncrypt(input, key);
			} else {
				output = otpDecrypt(input, key);
			}
		} else {
			cout << "Invalid cipher. Please enter caesar, vigenere, or otp." << endl;
			continue;
		}

		cout << "Output: " << output << endl;

		// Save to file
		ofstream outFile("ciphertext.txt");
		outFile << output;
		outFile.close();

		// Ask if user wants to repeat
		char repeat;
		cout << "Do you want to perform another operation? (y/n): ";
		cin >> repeat;
		if (tolower(repeat) != 'y') {
			break;
		}
	}

	return 0;
}
