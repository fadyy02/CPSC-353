#include "otp_cipher.h"

using namespace std;

// Function to generate a random key of the same length as the text
string generateRandomKey(int length) {
	string key = "";
	srand(static_cast<unsigned int>(time(0))); // Seed for randomness
	for (int i = 0; i < length; ++i) {
		char randomChar = 'A' + rand() % 26; // Random uppercase letter
		key += randomChar;
	}
	printf("OTP Key: %s", key.c_str());
	return key;
}

string otpEncrypt(string text, string key) {
	string result;
	for (size_t i = 0; i < text.length(); ++i) {
		if (isalpha(text[i])) {
			char offset = isupper(text[i]) ? 'A' : 'a';
			char k = toupper(key[i % key.length()]) - 'A';
			char c = ((text[i] - offset + k) % 26) + offset;
			result += c;
		} else {
			result += text[i];  // Non-alphabet characters are added directly
		}
	}
	return result;
}

string otpDecrypt(string text, string key) {
	string result;
	for (size_t i = 0; i < text.length(); ++i) {
		if (isalpha(text[i])) {
			char offset = isupper(text[i]) ? 'A' : 'a';
			char k = toupper(key[i % key.length()]) - 'A';
			char c = ((text[i] - offset - k + 26) % 26) + offset;
			result += c;
		} else {
			result += text[i];  // Non-alphabet characters are added directly
		}
	}
	return result;
}
