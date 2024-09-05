// otp.h
#ifndef OTP_H
#define OTP_H

#include <random>
#include <string>

using namespace std;

string generateRandomKey(int length);
string otpEncrypt(const string &text, const string &key);
string otpDecrypt(const string &text, const string &key);

#endif
