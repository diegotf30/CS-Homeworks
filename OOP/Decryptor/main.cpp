///Author: Diego Treviño Ferrer A00819313

//Description: Given a plaintext string, it encrypts it with a given key.
//		This program also has decrypting capabilities

#include <iostream>
#include <string>
#include <fstream>
#include "Encryptor.h"

using namespace std;

int main()
{
	ifstream ifInput;
	ofstream ofOutput;
	string sEncrypted;
    string sDecrypted;

    ifInput.open("msg.txt");
    if(!ifInput) //Fusible
	{
        cout << "ERROR 404:File not found" << endl;
        return 404;
	}
    getline(ifInput, sDecrypted);
    ifInput.close();

    int iKey = 1;
    string sContinue;
    Encryptor encryptor;

    do
	{
		iKey++;
		//sDecrypted = encryptor.decipher(sEncrypted,iKey); /*DECRYPT*/
		sEncrypted = encryptor.cipher(sDecrypted, iKey);
		cout << "Encrypted: "<< sEncrypted << endl;
		cout << "Decrypted: " << sDecrypted <<  "  Key = " << iKey << endl << endl;

		cout << "Press [ENTER] to continue or 'X' to exit: ";
		getline(cin, sContinue);
	}
	while ( (sContinue != "x") && (sContinue != "X") && (iKey < 100) );

    ofOutput.open("msg_encrypted.txt");

	ofOutput << sEncrypted;

	ofOutput.close();

    return 0;
}
