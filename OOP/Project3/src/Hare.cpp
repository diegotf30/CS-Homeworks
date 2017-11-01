#include "Hare.h"

//Default Constructor
Hare::Hare()
{
	iPos = 1;
	srand(time(NULL));
}

//Constructor
Hare::Hare(int iPos)
{
    this->iPos = iPos;

    srand(time(NULL)); /*Creates random seed*/
}

//Destructor
Hare::~Hare()
{
	//boom goes the dynami-err, i mean hare
}

//Setter
void Hare::setPos(int iPos)
{
	this->iPos = iPos;
}

//Getter
int Hare::getPos()
{
	return iPos;
}

//Methods
void Hare::move()
{
	int iMovement = 1 + ceil(rand() % 10);

	//Sleep. 20% (Nothing is done for lack of movement).
	/*
	if (iMovement <= 2)
	{
        iPos = iPos + 0;
	}
	*/

	//Big Jump. 20%
	if (iMovement == 3 || iMovement == 4)
	{
		iPos = iPos + 9;
	}
	//Big Slip. 10%
	else if (iMovement == 5)
	{
		iPos = iPos - 12;
	}
	//Small Jump. 30%
	else if (iMovement >= 6 && iMovement <= 8)
	{
        iPos++;
	}
	//Small Slip. 20%
	else if (iMovement == 9 || iMovement == 10)
	{
        iPos = iPos - 2;
	}
}
