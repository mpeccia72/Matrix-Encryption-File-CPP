#include <bits/stdc++.h>
#include <fstream>
using namespace std;

class encdec {
    int key[2][2];
 
    // File name to be encrypt
    string file = "message.txt";
    char c;
 
public:
    void encrypt();
    void decrypt();
};

void encdec::encrypt()
{
    int key[2][2]{
        {3, 5},
        {2, 3}
    };
    
     fstream fin, fout;
 
    // Open input file
    // ios::binary- reading file
    // character by character
    fin.open(file, fstream::in);
    
    for(int i = 0; i < 2; i++ ){   //This for loop is meant to read the input 2 characters at a time 
                                    
while (fin >> noskipws >> c) { //This while loop checks and makes sure there is no whitespace

        int temp = (c + key);
        fout << (char)temp;
    }
    
    fout.open("encrypted_message.txt", fstream::out);
    
    
    
    fin.close();
    fout.close();
}


void encdec::decrypt()
{
    int key[2][2]{
        {23, 5},
        {2, 23}
    };
    
    fstream fin;
    fstream fout;
    fin.open("encrypted_message.txt", fstream::in);
    
    fout.open("decrypted_message.txt", fstream::out);
 
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            
        }
    }
 
    fin.close();
    fout.close();
}


//References:

//Used to obtain the string through the use of a while loop

//https://stackoverflow.com/questions/12240010/how-to-read-from-a-text-file-character-by-character-in-c