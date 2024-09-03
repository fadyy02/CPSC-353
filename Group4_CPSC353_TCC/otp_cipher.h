// otp.h
#ifndef OTP_H
#define OTP_H

#include <string>

using namespace std;

string otpEncrypt(string text, string key);
string otpDecrypt(string text, string key);

#endif
