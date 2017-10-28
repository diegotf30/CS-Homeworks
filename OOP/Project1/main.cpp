///Author: Diego Treviño Ferrer A00819313

//Description: Given a .cpp file (adequately formated), it
//			   exports its documentation to a HTML file

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream ifInput;
    ofstream ofOutput;

	string sFile, sComStart, sWord, sAux;
    string sName, sAuthor, sDate;
	string sFunctionName[50];
	string sDesc[50];
	string sParam[50];
	string sReturn[50];

	bool bComEnd = false;

    cout << "What's the filename? (no extension)" << endl;
    getline(cin, sFile);

    //Reads .cpp file
    ifInput.open(sFile + ".cpp");

    ///Fusible
    if(!ifInput)
    {
		cout << "ERROR: File not found" << endl;
		return 404;
    }

    int i=0;

	//Reads name, author and date
	do
    {
        ifInput >> sComStart;

        if (sComStart == "/**")
        {
			do
            {
                ifInput >> sWord;

                if (sWord == "@progName")
				{
					getline(ifInput, sName);
				}
				else if (sWord == "@author")
				{
					getline(ifInput, sAuthor);
				}
                else if (sWord == "@date")
				{
					getline(ifInput, sDate);
				}
            }
            while (sWord != "*/");

            bComEnd = true;
        }
        else
        {
            //Skip line
        }
    }
    while(!ifInput.eof() && !bComEnd);

    bComEnd = false;

    i = 0;
    ///Reads each function comment, until eof
    do
	{
        do
		{
			ifInput >> sComStart;

			if (sComStart == "/**")
			{
				do
				{
					ifInput >> sWord;

					if (sWord == "@funcName")
					{
						getline(ifInput, sFunctionName[i]);
					}
					else if (sWord == "@desc")
					{
						getline(ifInput, sDesc[i]);
					}
					else if (sWord == "@param")
					{
						getline(ifInput, sParam[i]);
					}
					else if (sWord == "@return")
					{
						getline(ifInput, sReturn[i]);
					}
				}
				while (sWord != "*/");

				bComEnd = true;
			}
			else
			{
				///Skip line
				getline(ifInput, sAux);
			}
		}
		while(!ifInput.eof() && !bComEnd);

		bComEnd = false;
        i++;
	}
	while (!ifInput.eof());

    ifInput.close();

    //Makes HTML file
    ofOutput.open(sFile + ".html");

    ofOutput << "<!DOCTYPE html>" << endl;
    ofOutput << "<html>" << endl;

	ofOutput << "\t<head>" << endl;
	ofOutput << "\t\t<title>" << endl;
	ofOutput << "\t\t\tFile Documentation " << sFile << endl;
	ofOutput << "\t\t</title>" << endl;
	ofOutput << "\t</head>" << endl;

	ofOutput << "\t<body>" << endl;
	if (sName.length() > 0)
	{
		ofOutput << "\t\t<h2>" << endl;
		ofOutput << "\t\t\tProgram: " << sName << "<br>" << endl;
		ofOutput << "\t\t</h2>" << endl;
	}
    if (sAuthor.length() > 0)
	{
        ofOutput << "\t\t<strong> Author: </strong>" << sAuthor << "<br>" << endl;
	}
    if (sDate.length() > 0)
	{
        ofOutput << "\t\t<strong> Date of Creation: </strong>" << sDate << "<br>" << endl;
	}

    i = 0;
    while(sFunctionName[i].length() > 0)
	{
		ofOutput << "\t\t<h3>" << endl;
		ofOutput << "\t\t\t<hr>" << endl;
		ofOutput << "\t\t\t<br>Function: " << sFunctionName[i] << "<br>" << endl;
		ofOutput << "\t\t</h3>" << endl;

        if (sDesc[i].length() > 0)
		{
			ofOutput << "\t\t<strong> Description: </strong>" << sDesc[i] << "<br>" << endl;
		}
		if (sParam[i].length() > 0)
		{
			ofOutput << "\t\t<strong> Parameter: </strong>" << sParam[i] << "<br>" << endl;
		}
		if (sReturn[i].length() > 0)
		{
			ofOutput << "\t\t<strong> Return value: </strong>" << sReturn[i] << "<br>" << endl;
		}

		i++;
	}

	ofOutput << "\t</body>" << endl;

	ofOutput << "</html>" << endl;

	ofOutput.close();

    cout << "\nYour cpp file has been properly documentated." << endl;
    cout << "The file " << sFile << ".html has been created." << endl;

	return 0;
}
