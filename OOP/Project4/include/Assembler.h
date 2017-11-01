#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <string>
#include <fstream>

using namespace std;

class Assembler
{
	public:
		//Default Constructor
		Assembler() { }
		//Constructor
		Assembler(string sFile)
		{
            sInputFile = sFile + ".asm";
            sOutputFile = sFile + ".obj";
			ifInput.open(sInputFile);
		}
		//Destructor
		virtual ~Assembler() { }

        //Functions
        string transformLOC(string sCommand, string sLOC)
        {
        	string sMachineCode;

            if(sCommand == "IN")
			{
                sMachineCode = "0";
			}
			else if(sCommand == "OUT")
			{
                sMachineCode = "1";
			}
			else if(sCommand == "LDA")
			{
                sMachineCode = "2";
			}
			else if(sCommand == "STA")
			{
                sMachineCode = "3";
			}
			else if(sCommand == "ADD")
			{
                sMachineCode = "4";
			}
			else if(sCommand == "SUB")
			{
                sMachineCode = "5";
			}
			else if(sCommand == "JUMP")
			{
                sMachineCode = "6";
			}
			else if(sCommand == "BRAN")
			{
                sMachineCode = "7";
			}
			else if(sCommand == "BRAZ")
			{
                sMachineCode = "8";
			}
			//Adds locality to instruction code.
			sMachineCode += sLOC;

			if(sCommand == "HALT;")
			{
                sMachineCode = "999";
			}

			return sMachineCode;
        }

        void writeFile()
        {
        	string sCommand;
            string sLOC;
			string sAux;
			ofOutput.open(sOutputFile);

            do
			{
                ifInput >> sCommand;
				ifInput >> sLOC;
				//If there's a ';' at the end of the line, it removes it.
				if(sLOC.find(';'))
				{
					sLOC.pop_back();
				}

				ofOutput << transformLOC(sCommand, sLOC) << endl;

				//We get rid of the comments, go to next line
                getline(ifInput, sAux);

			}
			while(!ifInput.eof());

			ifInput.close();
			ofOutput.close();
        }

	protected:

	private:
		string sInputFile;
		string sOutputFile;
		ifstream ifInput;
		ofstream ofOutput;

};

#endif // ASSEMBLER_H
