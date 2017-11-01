#include "Tortoise.h"

//Default Constructor
Tortoise::Tortoise()
{
	iPos = 1;
	srand(time(NULL));
}

//Constructor
Tortoise::Tortoise(int iPos)
{
    this->iPos = iPos;

    srand(time(NULL));    /*Random seed*/
}

//Destructor
Tortoise::~Tortoise()
{
	//boom how sad he's destroyed :(
}

//Setter
void Tortoise::setPos(int iPos)
{
	this->iPos = iPos;
}

//Getter
int Tortoise::getPos()
{
	return iPos;
}

void Tortoise::move()
{
	int iMovement = 1 + ceil(rand() % 10);

	//Fast pace. 50%
	if (iMovement <= 5)
	{
        iPos = iPos + 3;
	}
	//Slip. 20%
	else if (iMovement == 6 || iMovement == 7)
	{
		iPos = iPos - 6;
	}
	//Slow pace. 30%
	else if (iMovement >= 8 && iMovement <= 10)
	{
        iPos++;
	}
}
