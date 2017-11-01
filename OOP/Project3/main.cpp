///Author: Diego Treviño Ferrer A00819313

///Description: This program makes a race between a hare and a tortoise;
///				who have different movement options in each cycle
///
///				The winner is he who gets to pos. 70 (or farther).

#include <iostream>
#include "Race.h"
#include "Hare.h"
#include "Tortoise.h"

using namespace std;

const int iTrack = 70;

int main()
{
	string sEnter;
	int iGanador = 0;

    Race race(iTrack);
    race.addAnimals(new Hare(), new Tortoise());

    cout << "Initial Pos: " << endl;
    cout << "T: " << 1 << endl;
    cout << "H: " << 1 << endl;

    cout << "\n\nBOOM!!!" << endl;
    cout << "AND THEY'RE OFF!!!" << endl << endl << endl;

    do
	{
		race.advance();
		iGanador = race.getWinner();
		cout << "\nPress ENTER to continue";
		getline(cin, sEnter);
	}while(iGanador == 0);

	if (race.getWinner() == 1)
	{
        cout << "\n\nTHE TORTOISE WINS YAY!" << endl;
	}
	else
	{
        cout << "\n\nThe hare wins, oh my :/" << endl;
	}

    return 0;
}
