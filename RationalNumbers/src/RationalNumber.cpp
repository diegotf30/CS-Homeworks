#include "RationalNumber.h"

#include <iostream>

using namespace std;

///Default Constructor
RationalNumber::RationalNumber()
{
	a = 1;
	b = 1;
}

///Constructor
RationalNumber::RationalNumber(int a, int b)
{
    this -> a = a;
    this -> b = b;
}

///Destructor
RationalNumber::~RationalNumber()
{
	//dtor
}

///Functions
void RationalNumber::add(RationalNumber& n)
{
    a = a * n.b + b * n.a;
    b = b * n.b;
}

void RationalNumber::sub(RationalNumber& n)
{
	a = a * n.b - b * n.a;
    b = b * n.b;
}

///Friend Functions
RationalNumber sum(const RationalNumber &n1, const RationalNumber &n2)
{
    RationalNumber temp;
    temp.a = n1.a * n2.b + n1.b * n2.a;
    temp.b = n1.b * n2.b;
    return temp;
}

RationalNumber operator +(const RationalNumber &n1, const RationalNumber &n2)
{
    RationalNumber temp;
    temp.a = n1.a * n2.b + n1.b * n2.a;
    temp.b = n1.b * n2.b;
    return temp;
}

RationalNumber operator -(const RationalNumber &n1, const RationalNumber &n2)
{
    RationalNumber temp;
    temp.a = n1.a * n2.b - n1.b * n2.a;
    temp.b = n1.b * n2.b;
    return temp;
}

RationalNumber operator *(const RationalNumber &n1, const RationalNumber &n2)
{
    RationalNumber temp;
    temp.a = n1.a * n2.a;
    temp.b = n1.b * n2.b;
    return temp;
}

RationalNumber operator /(const RationalNumber &n1, const RationalNumber &n2)
{
    RationalNumber temp;
    temp.a = n1.a * n2.b;
    temp.b = n1.b * n2.a;
    return temp;
}

///Operator overload
bool operator ==(const RationalNumber &n1, const RationalNumber &n2)
{
    return (n1.a * n2.b == n2.a * n1.b);
}

bool operator <(const RationalNumber &n1, const RationalNumber &n2)
{
    return (n1.a * n2.b < n1.a * n1.b);
}

ostream& operator <<(ostream &outs, const RationalNumber &numRacional)
{
   outs << numRacional.a << " / " << numRacional.b;
   return outs;
}
