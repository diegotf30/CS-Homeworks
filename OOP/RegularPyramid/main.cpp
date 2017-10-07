///Programmer: Diego Treviño.
///This program covers the subject of Class Composition, given a
///		regular pyramid (with an equilateral triangular base) it
///		calculates its superficial area.

#include <iostream>

#include "RegularPyramid.h"

using namespace std;

int main()
{
    RegularPyramid pyramid(Triangle(5,2), 5, 2);

    cout << "Superficial Area of the Pyramid is: " << pyramid.calcArea() << endl;
}
