#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include <exception>
#include <stdexcept>
#include <iostream>

using namespace std;

class MyException: public exception
{
    public:
        MyException();
        virtual ~MyException();
        const char* what() const throw()
        {
            return "c++ exception";
        }
    protected:

    private:
};

#endif // MYEXCEPTION_H
