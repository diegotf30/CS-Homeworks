///Programmer: Diego Treviño.
///This program covers the basic concept of Exceptions, and adds
///		a basic exception class (MyException).

#include <iostream>
#include <exception>
#include <stdexcept>
#include "MyException.h"

using namespace std;

int getValue(int arr[], int index)
{
    if(index >=4) throw range_error("Out of range");
    return arr[index];
}

int main()
{
    double dA, dB, dAnswer;
    cout << "Input a";
    cin >> dA;
    cout << "Input b";
    cin >> dB;

    //Exception 1
    try
    {
        if(b==0) throw "Divides by 0";
        dAnswer=dA/double(dB);
    }
    catch(char const* e)
    {
        cout << "error" << endl;
    }

    //Exception 2
    int ex=0;
    try
    {
        switch(ex)
        {
            case 1: throw 1; break;
            case 2: throw 'c'; break;
            case 3: throw true; break;

        }
    }
    catch(int e)
    {
        cout << "Error" << e << endl;
    }
    catch(char e)
    {
        cout << "Error" << e << endl;
    }
    catch(bool e)
    {
        cout << "Error" << e << endl;
    }

    //Exception 3
    int arr[]={1, 2, 3, 4};
    int val;
    try
    {
        val=getValue(arr,6);
    }
    catch(range_error e)
    {
        cout << "Error" << e.what() << endl;
        //What = Exception method that prints the error type.
    }
    /*
    //Exception 4 (In .h)
    class MyException: public exception
    {
        const char* what() const throw()
        {
            return "c++ exception";
        }
    }
    */
    try
    {
        throw MyException();
    }

    catch(MyException e)
    {
        cout << e.what();
    }
};
