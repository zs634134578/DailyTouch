/*
 *
 */

#include <iostream>

using namespace std;

#define debug(x, y) std::cout << "(debug)" << x << y << std::endl;
#define print(x) std::cout << x << std::endl;

class Solution
{

};
class A
{
public:
    A(){}
    virtual void aa() {}
private:
    char k[3];
};

class B:public A
{
public:
    B() {}
    virtual void bb() {}
private:
    char j[3];
};

class C:public B
{
public:
    C() {}
    virtual void cc() {}
private:
    char i[3];
};

int main()
{
    A* a = new A();
    B* b = new B();
    C* c = new C();
    
    debug("sizeof(a):", sizeof(*a));
    debug("sizeof(b):", sizeof(*b));
    debug("sizeof(c):", sizeof(*c));
    print("Hello world!");
    return 0;
}
