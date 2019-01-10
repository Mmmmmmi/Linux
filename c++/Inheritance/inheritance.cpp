/*
 *  这是一个继承的demo
 *
 *
*/

#include <iostream>
#include <string>
using namespace std;

struct Base
{
public:
    int _pubb;
protected:
    int _prob;
private:
    int _prib;
};

struct Derived :  Base
{
public:
    void test() 
    {
        _pubb = 1;
        _prob = 2;
  //      _prib = 3;
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
    Base b;
    Derived derived;
    derived._pubb = 1;
    return 0;
}

