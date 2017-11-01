#ifndef RACE_H
#define RACE_H

#include <string>
#include "Tortoise.h"
#include "Hare.h"

using namespace std;

class Race
{
	public:
		///Constructors
		Race();
		Race(int iEnd);
		///Destructor
		virtual ~Race();

		///Methods
		void advance();
		int getWinner();
		void addAnimals(Hare *hare, Tortoise *tortoise);

	protected:

	private:
		Hare *hare;
		Tortoise *tortoise;
		int iEnd;
};

#endif // RACE_H
