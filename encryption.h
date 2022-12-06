#include "./map.h"
#include <string>

using namespace std;

// C = (K*P)mod26
// P = (K-inverse*C)mod26

class CipherBlock {
    
    // key used to encrypt
    int key[2][2] = {
        {5, 7},
        {3, 4}
    };
    
    // inverse key to decrypt
    int inverseKey[2][2] = {
        {22, 7},
        {3, 21}
    };
    
    public:
        string encrypt(string);
        string decrypt(string);
};


// Precondition: a string is inputted
// Postcondition: the string will be encrypted using hill cipher
string CipherBlock::encrypt(string message) {
    
    int length = message.length();
    int* messageArr = new int[length+1]; // we use length + 1 incase we need to throw in a placeholder if the length is odd
    bool isOddLength = (length%2 == 1);
     
     // maps each character in the string into an array ... see "./map.h" for mapping configurations
    for(int i = 0; i < length; i++) {
        char letter = message.at(i);
        int num = letToNum[letter];
        messageArr[i] = num;
    }
    
    // if the encrypted string has a 0 at the end, it indicates that the original string is odd
    if(isOddLength) {
        messageArr[length] = '0';
    }
    
    message = ""; // clearing string so we can start building encrypted text to it
    
    for(int i = 0; i < length; i += 2) {
        // C = (K*P)mod26
        
        int num1 = (messageArr[i]*key[0][0] + messageArr[i+1]*key[1][0]);
        int num2 = (messageArr[i]*key[0][1] + messageArr[i+1]*key[1][1]);
        
        num1 = num1%26;
        num2 = num2%26;
        
        char let1 = numToLet[num1];
        char let2 = numToLet[num2];
        
        message = message + let1 + "" + let2;
        
    }
    
    if(isOddLength) {
        message = message + '0';
    }
    
    // memory leak prevention
    delete[] messageArr;
    
    return message;

}

// Note: copy and paste of encrypt function except for the key , which is replaced with an inverse key
// Precondition: a string is inputted
// Postcondition: the string will be decrypted using hill cipher
string CipherBlock::decrypt(string message) {
    
    int length = message.length();
    int* messageArr = new int[length]; 
    bool isOddLength = (message.at(length - 1) == '0'); // checks for '0' at the end to detect if odd
    
    if(isOddLength) length--;
    
    // maps each character in the string into an array ... see "./map.h" for mapping configurations
    for(int i = 0; i < length; i++) {
        char letter = message.at(i);
        int num = letToNum[letter];
        messageArr[i] = num;
    }
    
    message = ""; // clearing string so we can start building decrypted text to it
    
    for(int i = 0; i < length; i = i + 2) {
        // C = (K-inverse*P)mod26
        
        int num1 = (messageArr[i]*inverseKey[0][0] + messageArr[i+1]*inverseKey[1][0]);
        int num2 = (messageArr[i]*inverseKey[0][1] + messageArr[i+1]*inverseKey[1][1]);
        
        num1 = num1%26;
        num2 = num2%26;
        
        char let1 = numToLet[num1];
        char let2 = numToLet[num2];
        
        message = message + let1 + "" + let2;
        
    }
    
    // chops off incorrect element at the end
    if(isOddLength) {
        message = message.substr(0, message.length() - 1);
    }
    
    // memory leak prevention
    delete[] messageArr;
    
    return message;
    
}

