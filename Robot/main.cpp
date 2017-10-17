///Author: Diego Treviño Ferrer A00819313

//Description: This program covers the topic of class composition with operator overload.

#include <iostream>
#include <string>

#include "Arm.h"
#include "Leg.h"
#include "Camera.h"
#include "Robot.h"

using namespace std;

int main()
{
	Robot r1("Mr. Roboto", 15.8, Arm(3.6, 3), Leg(5, 2), Camera("1080p", "DLSR"));
	Robot r2("Robocop", 2.1, Arm(0.8, 0.2), Leg(1, 2), Camera("144p", "Webcam"));
	cout << r1 << endl;
	cout << r2 << endl;

	return 0;
}
