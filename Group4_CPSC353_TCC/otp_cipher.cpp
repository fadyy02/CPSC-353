#include "otp_cipher.h"

using namespace std;

// Function to generate a random key of the same length as the text
string generateRandomKey(const int length) {
	string key;
	random_device rd;   // Non-deterministic random number generator
	mt19937 gen(rd());  // Seed the generator
	uniform_int_distribution<> dis(0, 25); // Uniform distribution for A-Z (0-25)

	for (int i = 0; i < length; ++i) {
		const int randomIndex = dis(gen);           // Generate a number between 0-25
		const char randomChar = static_cast<char>('A' + randomIndex); // Explicit cast to char
		key += randomChar;
	}
	printf("OTP Key: %s\n", key.c_str());
	return key;
}

string otpEncrypt(const string &text, const string &key) {
	string result;
	for (size_t i = 0; i < text.length(); ++i) {
		int textValue, keyValue;

		// Map space to 26 and letters to 0-25
		if (text[i] == ' ') {
			textValue = 26;
		} else {
			textValue = toupper(text[i]) - 'A';
		}

		// Map key similarly (treat spaces in the key as well, if applicable)
		if (key[i % key.length()] == ' ') {
			keyValue = 26;
		} else {
			keyValue = toupper(key[i % key.length()]) - 'A';
		}

		// Encrypt using modulo 27 (for A-Z and space)
		int encryptedValue = (textValue + keyValue) % 27;

		// Convert encryptedValue back to character (space for 26, A-Z for 0-25)
		if (encryptedValue == 26) {
			result += ' ';
		} else {
			result += static_cast<char>('A' + encryptedValue);
		}
	}
	return result;
}

string otpDecrypt(const string &text, const string &key) {
	string result;
	for (size_t i = 0; i < text.length(); ++i) {
		int textValue, keyValue;

		// Map space to 26 and letters to 0-25
		if (text[i] == ' ') {
			textValue = 26;
		} else {
			textValue = toupper(text[i]) - 'A';
		}

		// Map key similarly (treat spaces in the key as well, if applicable)
		if (key[i % key.length()] == ' ') {
			keyValue = 26;
		} else {
			keyValue = toupper(key[i % key.length()]) - 'A';
		}

		// Decrypt using modulo 27 (for A-Z and space)
		int decryptedValue = (textValue - keyValue + 27) % 27;

		// Convert decryptedValue back to character (space for 26, A-Z for 0-25)
		if (decryptedValue == 26) {
			result += ' ';
		} else {
			result += static_cast<char>('A' + decryptedValue);
		}
	}
	return result;
}