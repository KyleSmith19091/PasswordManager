#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <assert.h>
#include "../include/PasswordManager.hpp"

using namespace std;

int main(int argc, char *argv[]){
    
    if(argc==1){
        cout << "Please provide arguments" << endl;
        return -1;
    }
    
    PasswordManager m;
    
    if(strcmp(argv[1],"-e")==0){
        string s = argv[2];
        m.encryptPassword(s, "Test");
        cout << s << "\n"; 
        m.decryptPassword(s, "Test"); 
        cout << s << "\n"; 
    }else if(strcmp(argv[1], "-c")==0){
        cout << "Creating password of length: " << argv[1] << endl;
        int length = atoi(argv[1]);
        string s = m.generatePassword(length);
        cout << s << endl;
    }

    return 0;
}
