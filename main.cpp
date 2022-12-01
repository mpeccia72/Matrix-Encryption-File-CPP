#include <iostream>
#include <fstream>
#include "./encryption.h"

using namespace std;

int main()
{
    
    string fileMessage;
    
    EncryptionDecryption my;
    my.insertKey();
    my.printInverse();
    cout << my.encrypt("Go") << endl;
    string en = my.encrypt("Go");
    cout << my.decrypt(en);

    // input and output file objects
    ifstream input;
    ofstream output;
    
    // opens the file of data
    input.open("message.txt");
    
    // puts text from input file into a string
    input >> fileMessage;
    
    // Checks if file fails to input
    if(input.fail()) {
        cout << "Failed to input file!\n";
        exit(0);
    }
    
    // creates output file called "num_ascended.txt"
    output.open("encrypted_message.txt");
    
    // Checks if output file fails
    if(output.fail()) {
        cout << "Failed to output file!\n";
        exit(1);
    }

    // closes both files
    input.close();
    output.close();
    
    return 0;
}
