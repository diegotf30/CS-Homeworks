#include "Rectangle.h"
#include <iostream>

using namespace std;

///Default Constructor
Rectangle::Rectangle()
{
	dBase =	0;
	dHeight = 0;
}

///Constructor
Rectangle::Rectangle(double dBase,	double dHeight)
{
	this->dBase = dBase;
    this->dHeight = dHeight;
}

///Destructor
Rectangle::~Rectangle()
{
	//cout <<	"Destructor"	<<	endl;
}

///Setters
void Rectangle::setBase(double dBase)
{
	this->dBase	= dBase;
}

void Rectangle::setHeight(double dHeight)
{
	this->dHeight = dHeight;
}

///Getters
double	Rectangle::getBase()
{
	return dBase;
}

double	Rectangle::getHeight()
{
	return dHeight;
}

double Rectangle::calcArea()
{
	return dBase	* dHeight;
}

double Rectangle::calcPerimeter()
{
	return dBase * 2	+ dHeight * 2;
}

void Rectangle::draw()
{
	for	(int i = 0; i < dHeight; i++)
	{
		for	(int j = 0; j < dBase; j++)
		{
			cout << "* ";
		}

		cout << endl;
	}
}
