#include "Robot.h"

#include <cctype>

using namespace std;

const int iRows = 20;
const int iColumns = 20;

///Default Constructor
Robot::Robot()
{
	iXPos = 0;
    iYPos = 0;

    //Empty 20x20 array
    for(int i = 0; i < iRows; i++)
	{
        for(int j = 0; j < iColumns; j++)
		{
            cLabyrinth[i][j] = ' ';
		}
	}
}

///Constructor
Robot::Robot(istream &ifFile)
{
	string sSupport;

	//We ignore the first line
    getline(ifFile, sSupport);

    getline(ifFile, sSupport); /*Initial pos is (X,Y)*/
    iXPos = sSupport[sSupport.size() - 4] - '0';
    iYPos = sSupport[sSupport.size() - 2] - '0';


    for(int i = 0; i < iRows; i++)
	{
        getline(ifFile, sSupport);

        for(int j = 0; j < iColumns; j++)
		{
            cLabyrinth[i][j] = sSupport[j];
		}
	}

	cLabyrinth[iXPos][iYPos] = 'R';
}

Robot::~Robot()
{
	//Destructor
}

///Methods
char Robot::move()
{
    cLabyrinth[iXPos][iYPos] = 'R';

	//Right is free
	if(cLabyrinth[iXPos + 1][iYPos] == ' ' || cLabyrinth[iXPos + 1][iYPos] == 'S')
	{
		cLabyrinth[iXPos][iYPos] = 'v';
		iXPos++;
	}
	//Down is free
	else if(cLabyrinth[iXPos][iYPos + 1] == ' '  || cLabyrinth[iXPos][iYPos + 1] == 'S')
	{
		cLabyrinth[iXPos][iYPos] = 'v';
		iYPos++;
	}
	//Left is free
	else if(cLabyrinth[iXPos - 1][iYPos] == ' '  || cLabyrinth[iXPos - 1][iYPos] == 'S')
	{
		cLabyrinth[iXPos][iYPos] = 'v';
		iXPos--;
	}
	//Up is free
	else if(cLabyrinth[iXPos][iYPos - 1] == ' '  || cLabyrinth[iXPos][iYPos - 1] == 'S')
	{
		cLabyrinth[iXPos][iYPos] = 'v';
		iYPos--;
	}
	///Dead-end, from whence thou came, thou shall remain. Until thou are complete again.
    else if(cLabyrinth[iXPos + 1][iYPos] == 'v')
	{
        cLabyrinth[iXPos][iYPos] = '-';
        iXPos++;
	}
	else if(cLabyrinth[iXPos][iYPos + 1] == 'v')
	{
        cLabyrinth[iXPos][iYPos] = '-';
        iYPos++;
	}
	else if(cLabyrinth[iXPos - 1][iYPos] == 'v')
	{
        cLabyrinth[iXPos][iYPos] = '-';
        iXPos--;
	}
	else if(cLabyrinth[iXPos][iYPos - 1] == 'v')
	{
        cLabyrinth[iXPos][iYPos] = '-';
        iYPos--;
	}

    //If there's no exit we advance
	if(cLabyrinth[iXPos][iYPos] != 'S')
	{
		cLabyrinth[iXPos][iYPos] = 'R';
	}

	return cLabyrinth[iXPos][iYPos];
}

void Robot::print()
{
	for(int i = 0; i < iRows; i++)
	{
        for(int j = 0; j < iColumns; j++)
		{
            cout << cLabyrinth[i][j];
		}
		cout << endl;
	}
}

void Robot::end()
{
	cLabyrinth[iXPos][iYPos] = 'R';

	system("cls");
    print();
}
