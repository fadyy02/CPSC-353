/*
 * Assignment Name: Three Classical Ciphers
 * Team Members: Fady Youssef, 
 *             Tyler Montague,
 *             Caedyn Reece,
 *             Steve Deibert
 * Course: CPSC 353
 * Date Submitted: 09/08/2024
 * Filename: main.cpp
 * 
 * Description: 
 * This program provides a simple command-line interface for encryption and decryption using three types of ciphers: 
 * Caesar, Vigenère, and One-Time Pad (OTP). The user is prompted to choose between encryption or decryption 
 * mode and then select a cipher type. The program then takes input text, applies the selected cipher using the specified key,                   
 * and outputs the result to both the console and text files. The program allows for repeated encryption/decryption 
 * operations.
 * 
 * Input/Output:
 * - Prompts user for mode (Encrypt/Decrypt), cipher type, input text, and key (Vigenère and OTP).
 * - Outputs the result to the console and saves it to a file.
 * - Saves the encryption/decryption key to a file (Vigenère and OTP).
 *
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
	int mode, cipher, shift;
	string input, output, key;

	while (true) {
		cout << "Enter mode (1: Encrypt, 2: Decrypt): ";
		cin >> mode;
		if (mode != 1 && mode != 2) {
			cout << "Invalid mode. Please enter 1 or 2." << endl;
			continue;
		}

		while (true) {
			cout << "Enter cipher (Caesar: 1, Vigenere: 2, OTP: 3): ";
			cin >> cipher;
			if (cipher == 1 || cipher == 2 || cipher == 3) {
				break;
			}
			cout << "Invalid cipher. Please enter 1, 2, or 3." << endl;
		}

		cout << "Enter input text: ";
		cin.ignore();  // Ignore newline character left in buffer
		getline(cin, input);
		for (auto &c : input) c = toupper(c);  // Convert input to uppercase

		if (cipher == 1) {
			cout << "Enter shift key (number): ";
			cin >> shift;
			if (mode == 1) {
				output = caesarEncrypt(input, shift);
			} else {
				output = caesarDecrypt(input, shift);
			}
		} else if (cipher == 2) {
			cout << "Enter key: ";
			cin >> key;
			for (auto &c : key) c = toupper(c);  // Convert key to uppercase
			if (mode == 1) {
				output = vigenereEncrypt(input, key);
			} else {
				output = vigenereDecrypt(input, key);
			}
		} else if (cipher == 3) {
			if (mode == 1) {
				key = generateRandomKey(input.length());
				output = otpEncrypt(input, key);
			} else {
				cout << "Enter key: ";
				cin >> key;
				for (auto &c : key) c = toupper(c);  // Convert key to uppercase
				output = otpDecrypt(input, key);
			}
		} else {
			cout << "Invalid cipher. Please enter caesar, vigenere, or otp." << endl;
			continue;
		}

		cout << "Output: " << output << endl;

		// Save cipher output to file
		ofstream cipherFile("ciphertext.txt");
		cipherFile << output;
		cipherFile.close();

		// Save cipher key to file
		if (cipher != 1) {
			ofstream keyFile("key_text.txt");
			keyFile << key;
			keyFile.close();
		}
		else {
			ofstream keyFile("shift_text.txt");
			keyFile << shift;
			keyFile.close();
		}

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
