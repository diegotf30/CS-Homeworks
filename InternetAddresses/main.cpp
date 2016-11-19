///Author: Diego Treviño Ferrer A00819313

///Reads the file "InetAddress.txt", stores the IP Address and hostname on the object
///		and displays it onto console

#include <iostream>
#include <string>
#include <fstream>
#include "InetAddress.h"

using namespace std;

int main()
{
    string sIP, sHostname, sLine;
    ifstream ifInput;
    int n = 0;

    InetAddress iaPage[50];

    ifInput.open("InetAddress.txt");

    ///Fusil
    if(!ifInput)
	{
		cout << "ERROR: File not found." << endl;
        return 404;
	}

	cout << "Hostname" << "\t\t\t" << "IP Address" << endl;
	cout << "------------------------------------------------" << endl;

    do
	{
        iaPage[n].readInetAddress(ifInput);
        n++;
	}
	while(!ifInput.eof());

	for (int i = 0; i < n; i++)
	{
		cout << iaPage[i].getHostname() << "\t\t\t"<< iaPage[i].getIP() << endl;
	}

    return 0;
}
