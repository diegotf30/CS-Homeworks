#include "Circle.h"
#include <math.h>
#include <iostream>
#define M_PI 3.1416

using namespace std;

//Default Constructor
Circle::Circle()
{
    dRadius = 0;
}

//Constructor
Circle::Circle(double dRadius)
{
    this -> dRadius = dRadius;
}

//Destructor
Circle::~Circle()
{
	cout <<	"Destructor" <<	endl;
}

//Setter
void Circle::setRadius(double dRadius)
{
	this -> dRadius = dRadius;
}

//Getter
double Circle::getRadius()
{
	return dRadius;
}

//Methods
double Circle::calcArea()
{
	return M_PI*pow(dRadius,2);
}

double Circle::calcPerimeter()
{
	return M_PI*(dRadius*2);
}
