///Author: Diego Trevino Ferrer A00819313

#include <iostream>
#include <string>
#include "Assembler.h"
#include "CPU.h"

using namespace std;

/*
 *Algorithm to follow:
 *
 *Read y;
 *while (y != 0)
 *{
 *	Read z;
 *	y = y - z;
 *	if (y<z)
 *	  Print y;
 *	else
 *	  Print z;
 *	Read y;
 *}
 *End;

 */

int main()
{
	string sFile;

    cout << "Give me the assembly file you want to process. (no extension)" << endl;
    cin >> sFile;

    Assembler assembler(sFile);
    assembler.writeFile();

    CPU computer(sFile);
    computer.simulate();


    return 0;
}
