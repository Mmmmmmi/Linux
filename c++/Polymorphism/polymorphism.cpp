#include <iostream>
using namespace std;
class A
{
public:
    virtual void test()
    {
        cout << " A" << endl;
    }
private:
    int A;
};
class B : public A
{
private:
virtual void test()
{
    cout << " A" << endl;
}
private:
    int B;
};
void funtest(A& a)
{
    a.test();
}
int main()
{
    A a;
    funtest(a);
    return 0;
}

