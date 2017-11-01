#ifndef TORTOISE_H
#define TORTOISE_H

#include <cstdlib> // Random numbers: rand(), srand()
#include <ctime> //For time()
#include <string>
#include <math.h> //For ceil(), eliminate decimal point.

using namespace std;

class Tortoise
{
	public:
		//Constructors
		Tortoise();
        Tortoise(int iPos);
        //Destructor
		virtual ~Tortoise();

		//Setter (In case iPos < 1)
		void setPos(int iPos);
        //Getter
        int getPos();

        //Methods
        void move();

	protected:

	private:
        int iPos; //Tortoise's actual position on the track.
};

#endif // TORTOISE_H
