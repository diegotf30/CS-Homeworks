#ifndef RFID_H
#define RFID_H

#include "CargoContainer.h"
#include <vector>
#include <string>

using namespace std;

class RFID : public CargoContainer
{
	public:
		//Constructors
		RFID();
		RFID(int id);
		//Destructor
		virtual ~RFID();

		//Methods
		void addManifest(string man);
		void printManifest(ofstream &outFile);

	protected:

	private:
		vector<string> sDescription;
};

#endif // RFID_H
