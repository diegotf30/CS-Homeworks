#ifndef INETADDRESS_H
#define INETADDRESS_H
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class InetAddress
{
	public:
		///Constructors
		InetAddress();
        InetAddress(string sIP, string sHostname);
        ///Destructor
		virtual ~InetAddress();

		///Setters
        void setIP(string sIP);
        void setHostname(string sHostname);
		///Getters
		string getIP();
		string getHostname();

		///Functions
		void readInetAddress(istream &iFile);

	protected:

	private:
        string sIP;
        string sHostname;
};

#endif // INETADDRESS_H
