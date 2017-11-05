#include "Manual.h"

using namespace std;

//Default Constructor
Manual::Manual()
{
	id = 0;
    sDescription.clear();
}
//Constructor
Manual::Manual(int id)
{
    this->id = id;
    sDescription.clear();
}
//Destructor
Manual::~Manual()
{
	//dtor
}

//Methods
void Manual::addManifest(string man)
{
    sDescription.push_back(man);
}

void Manual::printManifest(ofstream& outFile)
{
    outFile << "Container: " << id << " (Manual Container)" << endl;

    for(int i = 0; i < sDescription.size(); i++)
	{
        outFile << sDescription.at(i) << endl;
	}
}
