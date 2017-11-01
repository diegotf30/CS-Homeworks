#ifndef HARE_H
#define HARE_H

#include <cstdlib> // Random numbers: rand(), srand()
#include <ctime> //For time()
#include <string>
#include <math.h> //For ceil(), eliminate decimal point.

using namespace std;

class Hare
{
	public:
		//Constructors
		Hare();
        Hare(int iPos);
        //Destructor
		virtual ~Hare();

		//Setter (In case iPos < 1)
		void setPos(int iPos);
        //Getter
        int getPos();

        //Methods
        void move();

	protected:

	private:
        int iPos; //Hare's actual position on the track.
};

#endif // HARE_H
