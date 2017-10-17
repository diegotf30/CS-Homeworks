#ifndef ARM_H
#define ARM_H

#include <iostream>
#include <fstream>

using namespace std;

class Arm
{
	public:
		///Constructor
		Arm(double dLength, double dWidth)
		{
            this->dLength = dLength;
            this->dWidth = dWidth;
		}
		///Destructor
		virtual ~Arm() { }

        ///Getters
        double getLength() { return dLength; }
        double getWidth() { return dWidth; }

        ///Methods
        friend ostream& operator << (ostream &out, const Arm &aArm)
        {
			out << aArm.dLength << " " << aArm.dWidth;
			return out;
		}

	protected:

	private:
		double dLength;
		double dWidth;
};

#endif // ARM_H
