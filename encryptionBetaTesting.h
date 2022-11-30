using namespace std;

class EncryptionDecryption {
    int key[2][2] = {
        {1, 2},
        {3, 4}
    };
    int getDeterminate();
    public:
        void encrpyt();
        void decrypt();
        void insertKey();
        int** getInversekey();
};

// Precondition: class object exists
// Postcondition: the user will input via console what numbers they want in the 2x2 matrix key
void EncryptionDecryption::insertKey() {
    
    cout << "Enter 4 digits to insert into your 2x2 matrix key. Example: Inserting 1, 2, 3, 4 will be" << endl
         << "| 1 2 |" << endl
         << "| 3 4 |" << endl << endl;

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            cin >> key[i][j];
        }
    }
    
    cout << endl;
    
    // if the determinate of a matrix is 0, an inverse matrix cannot exist. we need to catch this error
    if(getDeterminate() == 0) {
        cout << "Invalid key. Inverse matrix does not exist because the matrix has a determinate of 0." << endl
             << "The following default matrix key below will be assigned by default. Restart program if you wish" << endl 
             << "for a different key." << endl << endl
             << "| 1 2 |" << endl
             << "| 3 4 |" << endl;
    }
    else {
        cout << "Your matrix key has been set to: " << endl << endl
             << "| " << key[0][0] << " " << key[0][1] << " |" << endl
             << "| " << key[1][0] << " " << key[1][1] << " |" << endl;
    }
    
}

// Note: private
// Precondition: a key exists
// Postcondition: returns the matrix determinate of the key
int EncryptionDecryption::getDeterminate() {
    int a = key[0][0] * key[1][1];
    int b = key[0][1] * key[1][0];
    return (a - b);
}





//References:

//Used to obtain the string through the use of a while loop

//https://stackoverflow.com/questions/12240010/how-to-read-from-a-text-file-character-by-character-in-c