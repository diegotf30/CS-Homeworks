#include <iostream>
#include "Circle.h"

using namespace std;

void readData(double &r)
{
    cout<<"Enter the radius: ";
    cin>>r;
}

void printResult(string sName, double dArea, double dPerimeter)
{
    cout << "Area of " << sName << " " << dArea << endl;
    cout << "Perimeter of " << sName << " " << dPerimeter << endl;
    cout << "----------------------------------"<< endl;
}

int main()
{
	double dArea;
	double dPerimeter;
	double dRadius;
	Circle circle1;

	dArea = circle1.calcArea();
	dPerimeter = circle1.calcPerimeter();

	printResult("Circle 1 = ",dArea,dPerimeter);

	readData(dRadius);
	Circle circle2 = Circle(dRadius);

	dArea= circle2.calcArea();
	dPerimeter = circle2.calcPerimeter();

	printResult("Circle 2 = ",dArea,dPerimeter);

	readData(dRadius);
	Circle circle3 = Circle(dRadius);

	dArea= circle3.calcArea();
	dPerimeter = circle3.calcPerimeter();

	printResult("Circle 3 = ",dArea,dPerimeter);

	return 0;
}
