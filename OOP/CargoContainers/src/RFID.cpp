#include "RFID.h"

using namespace std;

//Default Constructor
RFID::RFID()
{
	id = 0;
    sDescription.clear();
}
//Constructor
RFID::RFID(int id)
{
    this->id = id;

	sDescription.clear();
}

//Destructor
RFID::~RFID()
{
	//dtor
}

//Methods
void RFID::addManifest(string man)
{
    sDescription.push_back(man);
}

void RFID::printManifest(ofstream& outFile)
{
	int iNumRepetitions = 1;

	outFile << "Container: " << id << " (RFID Container)" << endl;

    for(int i = 0; i < sDescription.size(); i++)
	{
		//Checks how many times an element is repeated (e.g. "box of apples")
        for(int j = i + 1; j < sDescription.size(); j++)
		{
            if(sDescription.at(i) == sDescription.at(j))
			{
				iNumRepetitions++;
                sDescription.erase(sDescription.begin() + j);
			}
		}
		//Checks if last element is repeated
		if(sDescription.at(i) == sDescription.at(sDescription.size() - 1) && sDescription.size() > 2)
		{
			iNumRepetitions++;
			sDescription.pop_back();
		}

		if(iNumRepetitions == 1)
            outFile << "1 " << sDescription.at(i) << endl;
		else
		{
            //Box -> Boxes
			sDescription.at(i).insert(4, "es");

			outFile << iNumRepetitions << " " << sDescription.at(i) << endl;
		}

		iNumRepetitions = 1;
	}

}
