///Diego Treviño Ferrer A00819313

#include <iostream>
#include <RationalNumber.h>

using namespace std;

int main()
{
    RationalNumber n1(5,7);
    RationalNumber n2(3,4);
    RationalNumber n3;

    cout << "Rational Number N1: ";
    cout << n1 << endl;

    cout << "Rational Number N2: ";
    cout << n2 << endl << endl;;

    /*
    /// The result is stored in n1.
    n1.add(n2);
	cout << "Result of N1 + N2: ";
	cout << n1 << endl<<endl;

	n1.sub(n2);
	cout << "Result of N1 - N2: ";
	cout << n1 << endl<<endl;

	n3 = sum(n1,n2);
	cout << "Result of the sum N3 (N1 + N2): ";
	cout << n3 << endl;
	*/

	///Use of overloaded operators:
	n3 = n1 + n2;
	cout << "Sum of N1 + N2: ";
	cout << n3 << endl;

	n3 = n1 - n2;
    cout << "\nSubtraction of N1 - N2: ";
    cout << n3 << endl;

	n3 = n1 * n2;
    cout << "\nMultiplication N1 * N2: ";
    cout << n3 << endl;

    n3 = n1 / n2;
    cout << "\nDivision N1 / N2: ";
    cout << n3 << endl;

    cout << "------------------------------------" << endl;

	cout << "Rational Number N1: ";
	cout << n1 << endl;
	cout << "Rational Number N3: ";
	cout << n3 << endl << endl;

	if(n1 == n3 ) //Uses overloaded operator: '=='
		cout << "N1 y N3 are equal" << endl;
	else
		cout << "N1 y N3 are NOT equal" << endl;

	cout << endl;

	if(n1 < n3)
		cout << "N1 is smaller than N3" << endl;
	else
		cout << "N1 es bigger than N1" << endl;

    return 0;
}
