/*
 *  这是一个继承的demo
 *
 *
*/

#include <iostream>
#include <string>
using namespace std;

class Base
{
public:
    int _pubb;
protected:
    int _prob;
private:
    int _prib;
};

class Derive : private Base
{
public:
    void test() 
    {
        _pubb = 1;
        _prob = 2;
        _prib = 3;
    }
public:
    int _pubd;
protected:
    int _prod;
private:
    int _prid;
};





int main()
{
    Derive derive;
    derive._pubb = 1;
    derive._prob = 2;
    derive._prib = 3; 
    return 0;
}

