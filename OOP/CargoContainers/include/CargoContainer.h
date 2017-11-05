#ifndef CARGOCONTAINER_H
#define CARGOCONTAINER_H

#include <string>
#include <fstream>

using namespace std;

const int MAX = 10;

//This is a pure virtual class, thus not instantiated (no constructor)
class CargoContainer
{
	protected: //Only available to child classes
		int id;
	public:
		virtual void addManifest(string man) = 0;
		virtual void printManifest(ofstream &outFile) = 0;
};

#endif // CARGOCONTAINER_H
