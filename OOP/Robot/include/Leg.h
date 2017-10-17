#ifndef LEG_H
#define LEG_H

#include <iostream>
#include <fstream>

using namespace std;

class Leg
{
	public:
		///Constructor
		Leg(double dLength, int iNumLegs)
		{
            this->dLength = dLength;
            this->iNumLegs = iNumLegs;
		}
		///Destructor
		virtual ~Leg() { }

        ///Getters
        double getLength() { return dLength; }
        int getNumLegs() { return iNumLegs; }

        ///Methods
        friend ostream& operator << (ostream &out, const Leg &leg)
        {
			out << leg.dLength << " " << leg.iNumLegs;
			return out;
		}

	protected:

	private:
		double dLength;
		int iNumLegs;
};

#endif // LEG_H
