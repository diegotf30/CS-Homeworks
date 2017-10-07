#include "Triangle.h"

///Default Constructor
Triangle::Triangle()
{
	dBase = 0;
	dHeight = 0;
}

///Constructor
Triangle::Triangle(double dBase, double dHeight)
{
    this -> dBase = dBase;
    this -> dHeight = dHeight;
}

//Destructor
Triangle::~Triangle()
{
	//dtor
}

//Methods
double Triangle::calcPerimeter()
{
	return dBase * 3;
}

double Triangle::calcArea()
{
	return  (dBase * dHeight) / 2;
}
