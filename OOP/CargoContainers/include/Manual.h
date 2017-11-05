#ifndef MANUAL_H
#define MANUAL_H

#include "CargoContainer.h"
#include <vector>
#include <string>

using namespace std;

class Manual : public CargoContainer
{
	public:
		//Constructors
		Manual();
		Manual(int id);
		//Destructor
		virtual ~Manual();

		//Methods
		void addManifest(string man);
		void printManifest(ofstream &outFile);

	protected:

	private:
		vector<string> sDescription;
};

#endif // MANUAL_H
