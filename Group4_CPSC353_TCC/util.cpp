#include <iostream>
#include <string>
#include <cstdlib> // for exit()
#include "otp_cipher.h"
#include "vigenere_cipher.h"
#include "caesar_cipher.h"

using namespace std;

string text;
string key;
string expected;
string encValue;
string decValue;

// Helper function to check test results and exit if failed
void assertTest(const bool condition, const string& errorMessage) {
    if (!condition) {
        cout << errorMessage << endl;
        exit(EXIT_FAILURE); // Stop further execution if the test fails
    }
}

// Test Vigenère encrypt and decrypt using a known string
void vigenereTest() {
    text = "jesuits";
    key = "spo";
    expected = "ATFLXGJ";

    encValue = vigenereEncrypt(text, key);
    assertTest(encValue == expected, "Vigenere encrypt test failed, output: " + encValue);

    decValue = vigenereDecrypt(expected, key);
    assertTest(decValue == "JESUITS", "Vigenere decrypt test failed, output: " + decValue);

    cout << "Vigenere test passed." << endl;
}

// Test Caesar cipher encrypt and decrypt
void caesarTest() {
  constexpr int shift = 3;
    text = "HELLO WORLD";
    expected = "KHOORCZRUOG";

    encValue = caesarEncrypt(text, shift);
    assertTest(encValue == expected,
               "Caesar encrypt test failed, output: " + encValue);

    decValue = caesarDecrypt(expected, shift);
    assertTest(decValue == text, "Caesar decrypt test failed, output: " + decValue);

    cout << "Caesar test passed." << endl;
}

// Test OTP encrypt and decrypt
void otpTest() {
  text = "HELLO WORLD";
  key = generateRandomKey(static_cast<int>(text.length()));

  encValue = otpEncrypt(text, key);
  decValue = otpDecrypt(encValue, key);

    assertTest(decValue == text, "OTP decrypt test failed, output: " + decValue);

    cout << "OTP test passed." << endl;
}

void testCiphers() {
    caesarTest();
    vigenereTest();
    otpTest();
}