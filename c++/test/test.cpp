#include <iostream>

class A {
public:
    //析够函数
    A (int a = 0) {
        _a = a;
    }
    A (A&d);
private:
    //拷贝构造函数
  /*  A (A& d) {
        _a = d._a;
    }*/
    int _a;
};



int main()
{
    A a;
    return 0;
}

