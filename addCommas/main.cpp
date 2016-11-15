///Author: Diego Treviño Ferrer A00819313
///This program adds a comma every 1000 units to the input file and outputs the updated number.
///Date: August 2016

#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    ifstream ifInput;
    ofstream ofOutput;
    string sData[20];
    string sResult[20];
    ///Support variable when adding commas
    string sSupport, sFile;

    cout << "What file do you want processed? (no extension)" << endl;
    cin >> sFile;

    ifInput.open(sFile + ".txt");

    ///Fusible
    if(!ifInput)
    {
		cout << "ERROR: The file does not exist" << endl;
		return 404;
    }

    int iNumbers = 0;
    ///Passes the numbers from file to array.
    do
    {
		ifInput >> sData[iNumbers];
        iNumbers++;
    }
    while( !ifInput.eof() );

    ifInput.close();

    ///Adds a comma every 1000 units
    for (int i = 0; i < iNumbers; i++)
    {
        sResult[i] = "";

        while (sData[i].length() > 3)
        {
            sSupport = sData[i].substr(sData[i].length() - 3);
            sData[i].erase(sData[i].length() - 3);
            sResult[i]= "," + sSupport + sResult[i];
        }

        if (sData[i].length() <= 3)
        {
            sResult[i] = sData[i] + sResult[i];
        }
    }

    ///Prints the updated numbers onto file
    ofOutput.open("output.txt");
    for(int i = 0; i < iNumbers; i++)
    {
        ofOutput << sResult[i] << endl;
    }
    ofOutput.close();

    cout << "\n\nThe numbers in the file \""<< sFile << ".txt\" have been outputted with commas every 1000 units." << endl;

    return 0;
}



