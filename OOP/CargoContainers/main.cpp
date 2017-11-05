///Author: Diego Trevino Ferrer A00819313
///Description: This program reads "manifestos.txt" and formats it according to the
///				type of container, outputs global manifest in "output.txt"

#include <cstring> //fpr strcpy()
#include <cstdlib> //for atoi()
#include <fstream>
#include <iostream>
#include <string>
#include "CargoContainer.h"
#include "Manual.h"
#include "RFID.h"

using namespace std;

int main()
{
	ContenedorCarga *contenedor[MAX]; //To use polymorphism the array is of father class
	ifstream inFile;
	ofstream oFile;
	int id, type, pos, index=0;
	string line,value;
	char number[20]; //Char representation of a number

	//Input is manifest of each container
	//Output is global manifest of the shipment
	inFile.open("manifests.txt");
	oFile.open("output.txt");

	getline(inFile,line); //Discard first line (comments)
	getline(inFile,line);
	while( !inFile.eof() ) {
	  pos = line.find(' '); //We check if it's a new container
	  value = line.substr(0,pos);
	  strcpy( number, value.c_str() );
	  id = atoi(number); //char -> int
	  if( id > 1000){ //if ID > 1000, it's a cargo container
		  value = line.substr(pos); //Get container type
		  strcpy( number, value.c_str() );
		  type = atoi(number);
		  if( type == 1) // Manual container
			 contenedor[index++] = new ContenedorCargaManual(id);
		  else //type 2
			 contenedor[index++] = new ContenedorCargaRFID(id);
	  }
	  else //Part of an existing manifest, added to actual container
		  contenedor[index-1]->addManifiesto(line); //index points to next element (container) to be filled with data
	  getline(inFile,line);
	}
	//Output manifest
	for(int i=0; i<index ; i++) {
	  contenedor[i]->printManifiesto(oFile);
	  oFile << endl;
	}

	inFile.close();
	oFile.close();

   return 0;
}
