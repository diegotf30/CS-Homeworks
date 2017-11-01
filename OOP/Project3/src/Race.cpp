#include "Race.h"
#include <iostream>

//Default Constructor
Race::Race()
{
	iEnd = 2;
}

//Constructor
Race::Race(int iEnd)
{
	this->iEnd = iEnd;
}

//Destructor
Race::~Race()
{
	//dtor
}

//Metodos
void Race::advance()
{
    tortoise->move();
    hare->move();

    if (tortoise->getPos() < 1)
	{
        tortoise->setPos(1);
	}
	if (hare->getPos() < 1)
	{
        hare->setPos(1);
	}

	cout << "T: " << tortoise->getPos() << endl;
	cout << "H: " << hare->getPos() << endl;

	if (tortoise->getPos() == hare->getPos())
	{
        cout << "OUCH" << endl;
	}
}

int Race::getWinner()
{
	int iWinner = 0;

	//Tortoise wins!
	if (tortoise->getPos() >= iEnd)
	{
        iWinner = 1;
	}
	//Hare wins :(
	else if (hare->getPos() >= iEnd)
	{
        iWinner = 2;
	}

	return iWinner;
}

void Race::addAnimals(Hare *hare, Tortoise *tortoise)
{
	this->hare = hare;
	this->tortoise = tortoise;
}
