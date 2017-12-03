/*
 * =====================================================================================
 *
 *    Description: Given an encrypted message M, this program decodes it according to
 *	  the alchemist Arne Saknussemm's procedure, decoded message is printed in console.
 *
 *        Created:  18/01/2017
 *       Compiler:  gcc
 *
 *         Author:  Diego E. Treviño Ferrer A00819313
 *   Organization:  ITESM Campus Monterrey
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>

using namespace std;

int main(){
	int iLines = 0;
	//string[] == char[][]
	string sEncripted[50] = {};

	cout << "How many lines? ";
	cin >> iLines;

    //To use getline after cin.
	cin.ignore();
	cin.clear();

	cout << "Enter the message:" << endl;
	for ( int i = 0; i < iLines; i++ ){
		getline( cin, sEncripted[i] );
	}

	string sMessage = "";
	//The number of columns is the same for every row
	int iColumns = sEncripted[0].length();

	//Converts inverted bidimensional array to string.
	for ( int j = 1; j <= iColumns; j++ ){
		for ( int k = 1; k <= iLines; k++ ){
			sMessage += sEncripted[iLines - k][iColumns - j];
		}
	}

	//If the last char is '_' it's eliminated.
    while( sMessage[sMessage.length() - 1] == '_' ){
        sMessage.pop_back();
    }

    cout << "\nThe decoded message is: " << endl;

    int i = 0;

	while( i < sMessage.length() ){
		if( sMessage[i] == '_' ){
			sMessage[i] = ' ';
			i++;
		}
		//If '\' (ENTER) appears, prints what we have so far, and erases until the ENTER.
		else if( sMessage[i] == '\\' ){
            cout << sMessage.substr( 0, i ) << endl;
			sMessage.erase( 0, i + 1 );
			i = 0;
		}
		else {
			i++;
		}
	}

	//Prints last line.
	cout << sMessage << endl;

    return 0;
}
