#include "../include/PasswordManager.hpp"

PasswordManager::PasswordManager(){
    std::cout << "Creating Password Manager Object!\n"; 
}

std::string PasswordManager::generatePassword(const int length){
    
    std::string password = "";

    // Seed value from random number generation
    unsigned seed = time(0);
    
    // Seed the rand object
    std::srand(seed);

    for(int i = 0; i < length; i++){
        // Random value between 0 and 3
        int randVal = (std::rand() % 4);
        char c;
        switch(randVal){
            case 0: // Symbols
                c = (std::rand() % (ASCII_RANGES::SYMBOLS_END - ASCII_RANGES::SYMBOLS_START + 1) + ASCII_RANGES::NUMBERS_START);   
                break;
            case 1: // Numbers 
                c = (std::rand() % (ASCII_RANGES::NUMBERS_END - ASCII_RANGES::NUMBERS_START +1 ) + ASCII_RANGES::NUMBERS_START);
                break;
            case 2: // Uppercase letters
                c = (std::rand() % (ASCII_RANGES::UPPERCASE_LETTERS_END - ASCII_RANGES::UPPERCASE_LETTERS_START + 1) + ASCII_RANGES::UPPERCASE_LETTERS_START);
                break;
            case 3: // Lowercase letters
                c = (std::rand() % (ASCII_RANGES::LOWERCASE_LETTERS_END - ASCII_RANGES::LOWERCASE_LETTERS_START + 1) + ASCII_RANGES::LOWERCASE_LETTERS_START);
                break;
        }
        password += c;
    }
    return password;    
}

void PasswordManager::encryptPassword(std::string &password, const std::string key){
    // XOR key cipher
    for(int i = 0; i < password.size(); i++){
        password[i] = password[i] ^ key[i];
    }
}

void PasswordManager::decryptPassword(std::string &cipherText, const std::string key){
    // Decrypt XOR key cipher
    for(int i = 0; i < cipherText.size(); i++){
        cipherText[i] = cipherText[i] ^ key[i];
    }
}
