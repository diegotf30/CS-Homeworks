#ifndef CAMERA_H
#define CAMERA_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Camera
{
	public:
		///Constructor
		Camera(string sQuality, string sType)
		{
            this->sQuality = sQuality;
            this->sType = sType;
		}
		///Destructor
		virtual ~Camera() { }

		///Getters
        string getCalidad() { return sQuality; }
        string getTipo() { return sType; }

        ///Methods
        friend ostream& operator << (ostream &out, const Camera &cCamera)
        {
			out << cCamera.sQuality << " " << cCamera.sType;
			return out;
		}

	protected:

	private:
        string sQuality;
        string sType;
};

#endif // CAMERA_H
