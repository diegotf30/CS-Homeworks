#ifndef CAMARA_H
#define CAMARA_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Camara
{
	public:
		///Constructor
		Camara(string sQuality, string sType)
		{
            this->sQuality = sQuality;
            this->sType = sType;
		}
		///Destructor
		virtual ~Camara() { }

		///Getters
        string getCalidad() { return sQuality; }
        string getTipo() { return sType; }

        ///Methods
        friend ostream& operator << (ostream &out, const Camara &cCamara)
        {
			out << cCamara.sQuality << " " << cCamara.sType;
			return out;
		}

	protected:

	private:
        string sQuality;
        string sType;
};

#endif // CAMARA_H
