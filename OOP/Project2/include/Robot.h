#ifndef ROBOT_H
#define ROBOT_H

#include <fstream>
#include <istream>
#include <iostream>
#include <string>
#include <cstdlib> //for system()


using namespace std;

class Robot
{
	public:
		///Constructors
		Robot();
		Robot(istream &ifFile);
		///Destructor
		virtual ~Robot();
        ///Setters and Getters
        void setLabyrinth(istream &ifFile);
        char* getLabyrinth();

        ///Methods
		char move();
		void print();
		void end();

	protected:

	private:
        char cLabyrinth[20][20];
        int iXPos;
        int iYPos;
};

#endif // ROBOT_H
