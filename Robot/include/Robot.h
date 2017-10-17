#ifndef ROBOT_H
#define ROBOT_H

#include "Arm.h"
#include "Leg.h"
#include "Camera.h"

#include <iostream>
#include <string>

using namespace std;

class Robot
{
	public:
		///Constructors and Destructor
		Robot(string p_name, double p_height, const Arm p_arm, const Leg p_leg, const Camera p_camera):
            sName(p_name), dHeight(p_height), arm(p_arm), leg(p_leg), camera(p_camera) { }

		///Getters
        string getName() { return sName; }
        double getHeight() { return dHeight; }

        ///Methods
        friend ostream& operator << (ostream& out, const Robot& pRobot)
        {
			out << "\nName: " << pRobot.sName << "\nHeight: " << pRobot.dHeight << "m.\nArm: "
				<< pRobot.arm << "\nLeg: " << pRobot.leg <<" \nCamera: "<< pRobot.camera;
			return out;
		}

	protected:

	private:
		string sName;
        double dHeight;
        Arm arm;
        Leg leg;
        Camera camera;
};
#endif // ROBOT_H
