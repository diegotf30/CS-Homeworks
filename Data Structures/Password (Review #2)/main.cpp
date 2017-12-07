/*
 * =====================================================================================
 *
 *    Description: Validates a "password change" based on the specified number of times
 *	  inputted. A password is accepted if:
 *		 • It's different from the username or previous password
 *	  	 • At least 8 chars long
 *		 • Has one uppercase and one lowercase letter
 *		 • Has one digit and one special char (+,-,*,#,$)
 *		 • Doesn't have 3 consecutive digits or letters
 *
 *        Created:  28/01/2017
 *       Compiler:  gcc
 *
 *         Author:  Diego E. Treviño Ferrer A00819313
 *   Organization:  ITEaSM Campus Monterrey
 *
 * =====================================================================================
 */
#include <iostream>
#include <cctype>
#include <string>

#define iLengthPass sTestingPass.length()

using namespace std;

bool userAndPassNotEqual(string sTestingPass, string sUsername) {
	return sTestingPass != sUsername;
}
bool lastPassNotEqual(string sTestingPass, string sPassword) {
	return sTestingPass != sPassword;
}
bool isLengthValid(string sTestingPass) {
	return sTestingPass.length() >= 8;
}
bool hasAtLeastOneLowerCase(string sTestingPass) {
    bool bLowerCaseFound = false;
    unsigned int i = 0;

    while(!bLowerCaseFound && i < iLengthPass) {
        if (islower(sTestingPass[i])) {
			bLowerCaseFound = true;
        }
        i++;
    }
    return bLowerCaseFound;
}
bool hasAtLeastOneUpperCase(string sTestingPass) {
	bool bUpperCaseFound = false;
    unsigned int i = 0;

    while(!bUpperCaseFound && i < iLengthPass) {
        if (isupper(sTestingPass[i])) {
			bUpperCaseFound = true;
        }
        i++;
    }
    return bUpperCaseFound;
}
bool hasAtLeastOneDigit(string sTestingPass) {
	bool bDigitFound = false;
    unsigned int i = 0;

    while(!bDigitFound && i < iLengthPass) {
        if (isdigit(sTestingPass[i])) {
			bDigitFound = true;
        }
        i++;
    }
    return bDigitFound;
}
bool hasAtLeastOneSpecialChar(string sTestingPass) {
	bool bSpecialCharFound = false;
    unsigned int i = 0;

    while(!bSpecialCharFound && i < iLengthPass) {
        ///Si el caracter es '+','-','*','#' o '$' se termina.
        switch(sTestingPass[i]) {
			case '+':
			case '-':
			case '*':
			case '#':
			case '$':
				bSpecialCharFound = true;
				break;
			default:
				bSpecialCharFound = false;
        }
        i++;
    }
    return bSpecialCharFound;
}
bool hasEqualConsecChars(string sTestingPass) {
	bool bEqualConsecCharFound = false;
    unsigned int i = 0;

    while(!bEqualConsecCharFound && (i < iLengthPass - 1) ) {
        if ( sTestingPass[i] == sTestingPass[i + 1]) {
			bEqualConsecCharFound = true;
        }
        i++;
    }
    return bEqualConsecCharFound;
}
bool hasConsecDigits(string sTestingPass) {
	bool bConsecDigitsFound = false;
    unsigned int i = 0;

    while(!bConsecDigitsFound && i < (iLengthPass - 2) ) {
        if (isdigit(sTestingPass[i]) && sTestingPass[i + 1] == (sTestingPass[i] + 1)
			&& sTestingPass[i + 2] == (sTestingPass[i] + 2) ) {
			bConsecDigitsFound = true;
        }
        i++;
    }
    return bConsecDigitsFound;
}
bool hasConsecLetters(string sTestingPass) {
	bool bConsecLettersFound = false;
    unsigned int i = 0;

    while(!bConsecLettersFound && i < (iLengthPass - 2) ) {
        if ( isalpha(sTestingPass[i]) && isalpha(sTestingPass[i + 1]) && isalpha(sTestingPass[i + 2]) ) {
            string sMutableTestPass = sTestingPass;

            ///Las letras pueden ser mayusculas o minusculas (ej: aBc ABc abC AbC), por lo que se pasan
            ///		a minusculas en una variable de apoyo.
			for( int j = i; j < 3; j++ ) {
				sMutableTestPass[j] = tolower(sTestingPass[j]);
			}
			if( sMutableTestPass[i + 1] == (sMutableTestPass[i] + 1)
				&& sMutableTestPass[i + 2] == (sMutableTestPass[i] + 2) ) {
				bConsecLettersFound = true;
			}
		}
		i++;
	}
    return bConsecLettersFound;
}

int main() {
	string sUsername = "";
	string sPassword = "";
	int iNumPassToCheck = 0;

    cout << "Enter the username: ";
    cin >> sUsername;
    cout << "Enter the password: ";
    cin >> sPassword;
    cout << "How many times do you wish to validate the new password? ";
    cin >> iNumPassToCheck;
    cout << endl;

    string sTestingPass = "";

    for( int i = 0; i < iNumPassToCheck; i++ ) {
		cin >> sTestingPass;

		if( userAndPassNotEqual(sTestingPass, sUsername) && lastPassNotEqual(sTestingPass, sPassword) && isLengthValid(sTestingPass)
			&& hasAtLeastOneLowerCase(sTestingPass) && hasAtLeastOneUpperCase(sTestingPass) && hasAtLeastOneDigit(sTestingPass)
			&& hasAtLeastOneSpecialChar(sTestingPass) && !hasEqualConsecChars(sTestingPass) && !hasConsecDigits(sTestingPass)
			&& !hasConsecLetters(sTestingPass) ) {
			cout << "YES " << sTestingPass << endl;
		}
		else {
			cout << "NO " << sTestingPass << endl;
		}
    }

    return 0;
}
