#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

#include <iostream>

using namespace std;

class RationalNumber
{
	public:
		///Default Constructor
		RationalNumber();
		///Constructor
		RationalNumber(int a, int b);
		///Destructor
		virtual ~RationalNumber();

        ///Methods
		void add(RationalNumber &n);
		void sub(RationalNumber &n);

		///The 'friend' functions can access directly the class' attributes.
		friend RationalNumber sum(const RationalNumber &n1, const RationalNumber &n2);
		friend RationalNumber operator +(const RationalNumber &n1, const RationalNumber &n2);
		friend RationalNumber operator -(const RationalNumber &n1, const RationalNumber &n2);
		friend RationalNumber operator *(const RationalNumber &n1, const RationalNumber &n2);
		friend RationalNumber operator /(const RationalNumber &n1, const RationalNumber &n2);
        ///Operator Overload.
		friend bool operator ==(const RationalNumber &n1, const RationalNumber &n2);
		friend bool operator  <(const RationalNumber &n1, const RationalNumber &n2);
		friend ostream& operator <<(ostream& outs, const RationalNumber &rationalNum);

	protected:

	private:
		///Numerator
		int a;
		///Denominator
		int b;
};

#endif // RATIONALNUMBER_H
