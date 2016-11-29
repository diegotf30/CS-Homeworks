///Programmer: Diego Treviño.
///This program does basic operations on the class Rectangle based on user input.
///		It draws the rectangle accordingly.

#include <iostream>
#include <string>
#include "Rectangle.h"
using namespace std;

void readRectangle(double &b, double &h)
{
	cout << "Enter the base ";
	cin >> b;
	cout << "Enter the height ";
	cin >> h;
}

void outputResult(string sName, double dArea, double dPerimeter)
{
    cout << "Area of " << sName << dArea << endl;
    cout << "Perimeter of "<< sName << dPerimeter << endl;
    cout << "------------------------------" << endl;
}
int main()
{
	double dArea;
    double dPerimeter;
    double dBase;
    double dHeight;
    Rectangle rect1, rect2, rect3;
2
    dArea = rect1.calcArea();
    dPerimeter = rect1.calcPerimeter();
    rect1.draw();
    outputResult("Rectangle 1 = ",dArea,dPerimeter);

    readRectangle(dBase,dHeight);
    rect2 = Rectangle(dBase,dHeight);
    dArea = rect2.calcArea();
    dPerimeter = rect2.calcPerimeter();
    rect2.draw();
    outputResult("Rectangle 2 = ",dArea,dPerimeter);

    readRectangle(dBase,dHeight);
    rect3 = Rectangle(dBase,dHeight);
    dArea = rect3.calcArea();
    dPerimeter = rect3.calcPerimeter();
    rect3.draw();
    outputResult("Rectangle 3 = ",dArea,dPerimeter);
    return 0;
}
