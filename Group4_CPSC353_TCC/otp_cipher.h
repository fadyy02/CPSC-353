// otp.h
#ifndef OTP_H
#define OTP_H

#include <string>
#include <cctype>
#include <random>

using namespace std;

string generateRandomKey(int length);
string otpEncrypt(string text, string key);
string otpDecrypt(string text, string key);

#endif
