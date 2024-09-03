#include "otp_cipher.h"
#include <cctype>

using namespace std;

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
