#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// Generate Password
// Encrypt password
// Decrypt
// File manager

class PasswordManager{
    
    public:
        PasswordManager();
        std::string generatePassword(const int);
        std::vector<std::string> readPasswords();                
        void encryptPassword(std::string &,const std::string);
        void decryptPassword(std::string &,const std::string);

    private:    
        enum ASCII_RANGES{
            SYMBOLS_START = 33,
            SYMBOLS_END = 47,
            NUMBERS_START = 48,
            NUMBERS_END = 57,
            UPPERCASE_LETTERS_START = 65,
            UPPERCASE_LETTERS_END = 90,
            LOWERCASE_LETTERS_START = 97,
            LOWERCASE_LETTERS_END = 122
        };       
};
