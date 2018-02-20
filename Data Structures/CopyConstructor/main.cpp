/*
 * =====================================================================================
 *
 *    Description: Activity to grasp concept of Copy Constructors
 *
 *        Created:  03/02/2017
 *       Compiler:  gcc
 *
 *         Author:  Diego E. Treviño Ferrer A00819313
 *   Organization:  ITESM Campus Monterrey
 *
 * =====================================================================================
 */
class Example {
	private:
		int *pP;
	public:
		//Default Constructor
		Example() {pP = new int; *pP = 5;}
		//Copy Constructor
		Example(const Example &W) {
			pP = new int;
			*pP = *(W.pP);
		}
		~Example() { delete pP; }

		void print() { cout << *pP << endl; }
		void set(int j) { *pP = j; }

		//Overload
		Example& operator= (const Example &w) {
			if (this != &w) {
				//Deletes memory from 'this'
				delete pP;
				//Copy Constructor
				pP = new int;
				*pP = *(w.pP);
			}
			return *this;
		}
};

//Functions
void calc(Example z) {
	z.set(18);
	z.print();
}

Example doesntBreak() {
	Example T;
	T.set(555);
	return T;
}

int main() {
    Example E;
    E.print();
    calc(E);
    E.print();
    E.set(21);

    Example D(E); //Copy Constructor employed
	D.print();

	Example x = doesntBreak(); //Overload '=' and Copy Constructor
	x.print();

	Example A, B;
	A = B; //Overload of '='
	return 0;
}
