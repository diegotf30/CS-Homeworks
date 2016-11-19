#include "InetAddress.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

///Default Constructor
InetAddress::InetAddress()
{
    sIP = "";
    sHostname = "";
}

///Constructor
InetAddress::InetAddress(string sIP, string sHostname)
{
    this -> sIP = sIP;
    this -> sHostname = sHostname;
}

InetAddress::~InetAddress()
{
	//Destructor
}

///Setters
void InetAddress::setIP(string sIP)
{
	this -> sIP = sIP;
}

void InetAddress::setHostname(string sHostname)
{
	this -> sHostname = sHostname;
}

///Getters
string InetAddress::getIP()
{
	return sIP;
}

string InetAddress::getHostname()
{
	return sHostname;
}

///Method
void InetAddress::readInetAddress(istream &iFile)
{
    string sIP, sHostname;

    getline(iFile, sHostname);
    getline(iFile, sIP);

    this->setHostname(sHostname);
    this->setIP(sIP);
}
