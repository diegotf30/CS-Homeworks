#ifndef CPU_H
#define CPU_H

#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h> //for system()

using namespace std;

class CPU
{
	public:
		//Default Constructor
		CPU() { }
		//Constructor
        CPU(string sFile)
        {
			sInputFile = sFile + ".obj";
			//Empty array of 22 elements.
			vData.assign(22, 0);
			ifInput.open(sInputFile);
        }
        //Destructor
		virtual ~CPU() { }

        //Functions
        void printData()
        {
            for(int i = 0; i < 22; i++)
			{
                cout << (i + 1) << ": " << vData.at(i) << endl;
			}
			cout << endl << "IR: " << IR << "	  PC: " << PC << "	  AC: " << AC << endl;
        }

        void simulate()
        {
        	system("cls");

        	int iLine = 0;
        	IR = 0;
        	PC = 0;
        	AC = 0;

            do
			{
				ifInput >> iLine;

				//Actual instruction
				IR = iLine / 100;
				//Locality where actual inst. is being executed
				PC = iLine % 100;
				//
				switch(IR)
				{
					//IN
					case 0:
						cout << "--IN--" << endl;
						printData();
						cout << "IN: ";
						cin >> vData.at(PC);
						cout << endl;
						break;
					//OUT
					case 1:
						cout << "--OUT--" << endl;
						printData();
						cout << "OUT: " << vData.at(PC) << endl << endl;
						break;
					//LDA
					case 2:
						cout << "--LDA--" << endl;
						AC = vData.at(PC);
						printData();
						cout << endl;
						break;
					//STA
					case 3:
						cout << "--STA--" << endl;
                        vData.at(PC) = AC;
                        printData();
                        cout << endl;
						break;
					//ADD
					case 4:
						cout << "--ADD--" << endl;
                        AC += vData.at(PC);
                        printData();
                        cout << endl;
						break;
					//SUB
					case 5:
						cout << "--SUB--" << endl;
						AC -= vData.at(PC);
                        printData();
                        cout << endl;
						break;
					//JUMP
					case 6:
						cout << "--JUMP--" << endl;
						printData();
                        cout << endl;
						break;
					//BRAN
					case 7:
						cout << "--BRAN--" << endl;
						if(AC < 0)
						{
							PC = iLine % 100;
						}
						else
						{
							PC = 0;
						}

						printData();
                        cout << endl;
						break;
					//BRAZ
					case 8:
						cout << "--BRAZ--" << endl;
						if(AC == 0)
						{
							PC = iLine % 100;
						}
						else
						{
							PC = 0;
						}

						printData();
                        cout << endl;
						break;
					//HALT
					case 9:
						cout << endl << endl << "FIN." << endl << endl;
						break;
				}
				system("PAUSE");
                system("cls");
			}
			while(!ifInput.eof());

			ifInput.close();
        }

	protected:

	private:
		vector<int> vData;
        ifstream ifInput;
        string sInputFile;
		int IR; //Instruction Register
		int PC; //Program Counter
		int AC; //Accumulator
};

#endif // CPU_H
