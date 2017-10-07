#ifndef REGULARPYRAMID_H
#define REGULARPYRAMID_H

#include "Triangle.h"

class RegularPyramid
{
	public:
		///Constructor Default
		RegularPyramid();
		///Constructor
		RegularPyramid(Triangle triangle, double dLengthBase, double dLengthSide);

		///Destructor
		virtual ~RegularPyramid();

        ///Methods
        double calcArea();

	protected:

	private:
		Triangle triangle;
		double dLengthBase;
		double dLengthSide;
};

#endif // REGULARPYRAMID_H
