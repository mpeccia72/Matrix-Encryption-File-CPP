using namespace std;

class EncryptionDecryption {
    int key[4] = {1, 2, 3, 4};
    int getDeterminate();
    int* getAdjacent();
    public:
        string encrypt(string);
        string decrypt(string);
        void insertKey();
        double* getInverseKey();
        void printInverse();
};

// Precondition: class object exists
// Postcondition: the user will input via console what numbers they want in the 2x2 matrix key
void EncryptionDecryption::insertKey() {
    
    cout << "Enter 4 digits to insert into your 2x2 matrix key. Example: Inserting 1, 2, 3, 4 will be" << endl
         << "| 1 2 |" << endl
         << "| 3 4 |" << endl << endl;

    for(int i = 0; i < 4; i++) {
            cin >> key[i];
    }
    
    cout << endl;
    
    // if the determinate of a matrix is 0, an inverse matrix cannot exist. we need to catch this error
    if(getDeterminate() == 0) {
        cout << "Invalid key. Inverse matrix does not exist because the matrix has a determinate of 0." << endl
             << "The following default matrix key below will be assigned by default. Restart program if you wish" << endl 
             << "for a different key." << endl << endl
             << "| 1 2 |" << endl
             << "| 3 4 |" << endl;
             
             key[0] = 1; key[1] = 2; key[2] = 3; key[3] = 4;
             
    }
    else {
        cout << "Your matrix key has been set to: " << endl << endl
             << "| " << key[0] << " " << key[1] << " |" << endl
             << "| " << key[2] << " " << key[3] << " |" << endl;
    }
    
    cout << endl;
    
}

// Note: private
// Precondition: a key exists
// Postcondition: returns the matrix determinate of the key
int EncryptionDecryption::getDeterminate() {
    int a = key[0] * key[3];
    int b = key[1] * key[2];
    return (a - b);
}

int* EncryptionDecryption::getAdjacent() {
    int* adj = new int[4];
    adj[0] = key[3];
    adj[1] = -(key[1]);
    adj[2] = -(key[2]);
    adj[3] = key[0];
    
    return adj;
}

// Note: we use a double because inverse matricies commonly have fractions
// Precondition: a key exists
// Postcondition: returns the inverse matrix of the key in the form of a double array
double* EncryptionDecryption::getInverseKey() {
    double* inverse = new double[4];
    int determinant = getDeterminate();
    int* adj = getAdjacent();
    
    // linear algebra inverse calculations
    inverse[0] = (1.0/static_cast<double>(determinant))*static_cast<double>(adj[0]);
    inverse[1] = (1.0/static_cast<double>(determinant))*static_cast<double>(adj[1]);
    inverse[2] = (1.0/static_cast<double>(determinant))*static_cast<double>(adj[2]);
    inverse[3] = (1.0/static_cast<double>(determinant))*static_cast<double>(adj[3]);
    
    delete[] adj;
    
    return inverse;
}

void EncryptionDecryption::printInverse() {
    double* a = getInverseKey();
    cout << "Your matrix key has been set to: " << endl << endl
         << "| " << a[0] << " " << a[1] << " |" << endl
         << "| " << a[2] << " " << a[3] << " |" << endl;
}

string EncryptionDecryption::encrypt(string message) {
    string encryptedMessage = "";
    int len = message.length();
    int* messageArray = new int[len];
    for(int i =0; i < len; i++) {
        messageArray[i] = message.at(i); // takes ascii value
    }
    
    // we treat this as we are multiplying a 2 x 2 array by a 2 x n 
    
    int midpoint = (len+1)/2;
    
    for(int i = 0; i < midpoint; i++) {
        char ascii = static_cast<int>(key[0]*static_cast<double>(messageArray[i]) + key[1]*static_cast<double>(messageArray[i+midpoint]));
        encryptedMessage = encryptedMessage + ascii;
    }
    
    for(int i = midpoint; i < len; i++) {
        char ascii = static_cast<int>(key[2]*static_cast<double>(messageArray[i]) + key[3]*static_cast<double>(messageArray[i+midpoint]));
        encryptedMessage = encryptedMessage + ascii;
    }
    
    return encryptedMessage;
    
}

string EncryptionDecryption::decrypt(string message) {
    string decryptedMessage = "";
    int len = message.length();
    int* messageArray = new int[len];
    double* inverseKey = getInverseKey();
    for(int i =0; i < len; i++) {
        messageArray[i] = message.at(i); // takes ascii value
    }
    
    // we treat this as we are multiplying a 2 x 2 array by a 2 x n 
    
    int midpoint = (len+1)/2;
    
    for(int i = 0; i < midpoint; i++) {
        char ascii = static_cast<int>(inverseKey[0]*static_cast<double>(messageArray[i]) + inverseKey[1]*static_cast<double>(messageArray[i+midpoint]));
        decryptedMessage = decryptedMessage + ascii;
    }
    
    for(int i = midpoint; i < len; i++) {
        char ascii = static_cast<int>(inverseKey[2]*static_cast<double>(messageArray[i]) + inverseKey[3]*static_cast<double>(messageArray[i+midpoint]));
        decryptedMessage = decryptedMessage + ascii;
    }
    
    return decryptedMessage;
}





//References:

//Used to obtain the string through the use of a while loop
// https://www.youtube.com/watch?v=g1Bu4FiJVyQ&ab_channel=CppNuts

//https://stackoverflow.com/questions/12240010/how-to-read-from-a-text-file-character-by-character-in-c