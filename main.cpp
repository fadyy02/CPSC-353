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

using namespace std;

int main(int argc, char* argv[]) {
    int mode;
    string input,output;

    int mode = atoi(argv[1]); // 1: encrypt, 2: decrypt
    string cipher = argv[2]; // caesar, vigenere, otp
    string input = argv[3]; // text to be encrypted/decrypted

    cipher = toupper(cipher[0]); // check   
    input  = toupper(input[0]); // check


    if (argc != 4 && argc != 5) { // Check for the correct number of arguments
        cout << "Usage: " << argv[0] << "<mode> <cipher> <input>" << endl;
        cout << "Modes: 1 for encrypt, 2 for decrypt" << endl;
        cout << "Ciphers: caesar, vigenere, otp" << endl;
        cout << "Input: text to be encrypted/decrypted" << endl;
        exit(1);
    }

    return 0;
}
