#include <iostream>
#include <fstream>
#include "./encryption.h"

using namespace std;

int main() {
    
    // input and output file objects
    ifstream input;
    ofstream output1, output2;

    // opens the file of data
    input.open("message.txt");
    
    // Checks if file fails to input
    if(input.fail()) {
        cout << "Failed to input file!\n";
        exit(0);
    }
    
    // Creating object of CipherBlock
    CipherBlock cipher;
    
    // input data from file into string called message
    string message;
    input >> message;
    
    // opens file to store encrypted message called "encrypted_message.txt"
    output1.open("encrypted_message.txt");
    
    // Checks if output file fails
    if(output1.fail()) {
        cout << "Failed to output file!\n";
        exit(1);
    }
    
    // puts encrypted text into file
    string encryptedMessage = cipher.encrypt(message);
    output1 << encryptedMessage;
    
    // creates output file to store decrypted message called "result_message.txt"
    output2.open("result_message.txt");
    
    // Checks if output file fails
    if(output2.fail()) {
        cout << "Failed to output file!\n";
        exit(1);
    }
    
    // puts decrypted text into file
    output2 << cipher.decrypt(encryptedMessage);;

    // closes both files
    input.close();
    output1.close();
    output2.close();
    
    return 0;
    
}