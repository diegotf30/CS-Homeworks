///Author: Diego Treviño Ferrer A00819313

///Description: Given a text file (formated like a maze),
///				the "robot" finds the exit, and displays the
///				route

#include <cstdlib> //for system(), clearing console
#include <fstream>
#include <iostream>
#include "Robot.h"

using namespace std;

int main()
{
	ifstream file;
	char index;  //Char behind the robot
	string enter;
	int iLabyrinth = 0;

	do
	{
		cout << "Which labyrinth do you want? (1-4)" << endl;
		cin >> iLabyrinth;

		switch(iLabyrinth)
		{
			case 1:
				file.open("labyrinth.txt");
				break;
			case 2:
				file.open("labyrinth2.txt");
				break;
			case 3:
				file.open("labyrinth3.txt");
				break;
			case 4:
				file.open("labyrinth4.txt");
				break;
			default:
                cout << "Invalid number, enter a number 1-4" << endl << endl;
                break;
		}
	}
	while(iLabyrinth < 1 || iLabyrinth > 4);

	Robot robot(file); //Fills labyrinth with file data
	file.close();

	cout << "Press ENTER to continue.";
	getline(cin, enter);

	do
	{
	  system("cls"); ///Clears console
	  robot.print(); //Displays labyrinth

	  cout << "Press ENTER to continue.";
	  getline(cin, enter);

	  index = robot.move(); ///move() return previous char
	}
	while(index != 'S');

	robot.terminar(); ///Destroys labyrinth (dynamic array)

	cout << "\nTHE ROBOT FOUND THE EXIT!\n Press ENTER to end.";
	getline(cin, enter);

	return 0;
}
