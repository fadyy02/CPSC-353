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
		if (isalpha(text[i])) {
			const char offset = isupper(text[i]) ? 'A' : 'a';
			const int k = toupper(key[i % key.length()]) - 'A'; // Convert key to int
			const char c = static_cast<char>(((text[i] - offset + k) % 26) + offset); // Explicit char cast
			result += c;
		} else {
			result += text[i];  // Non-alphabet characters are added directly
		}
	}
	return result;
}

string otpDecrypt(const string &text, const string &key) {
	string result;
	for (size_t i = 0; i < text.length(); ++i) {
		if (isalpha(text[i])) {
			const char offset = isupper(text[i]) ? 'A' : 'a';
			const int k = toupper(key[i % key.length()]) - 'A'; // Convert key to int
			const char c = static_cast<char>(((text[i] - offset - k + 26) % 26) + offset); // Explicit char cast
			result += c;
		} else {
			result += text[i];  // Non-alphabet characters are added directly
		}
	}
	return result;
}
