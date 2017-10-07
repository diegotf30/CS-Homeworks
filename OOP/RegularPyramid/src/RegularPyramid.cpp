#include "RegularPyramid.h"

///Constructor Default
RegularPyramid::RegularPyramid()
{
    triangle = Triangle();
    dLengthBase = 0;
    dLengthSide = 0;
}

///Constructor
RegularPyramid::RegularPyramid(Triangle triangle, double dLengthBase, double dLengthSide)
{
    this -> triangle = triangle;
    this -> dLengthBase = dLengthBase;
    this -> dLengthSide = dLengthSide;
}

///Destructor
RegularPyramid::~RegularPyramid()
{
	//dtor
}

///Methods
double RegularPyramid::calcArea()
{
    double dAreaBase;
    double dAreaSide;

    dAreaBase = dLengthBase * dLengthBase;
    dAreaSide = 4 * ((dLengthBase * dLengthSide)/2);

    return dAreaBase + dAreaSide;
}
