/*
 * 运行时类型识别 RTTI
 */

#include <iostream>
#include <typeinfo>

using namespace std;

#define debug(x, y) std::cout << "(debug)" << x << y << std::endl;
#define print(x) std::cout << x << std::endl;

class Base 
{
public:
    virtual void funcA()
    {
        cout << "Base" << std::endl;
    }
};

class Derived:public Base
{
public:
    virtual void funcB()
    {
        print("Derived");
    }
};

void funcC(Base* p)
{
    Derived *dp = dynamic_cast<Derived*>(p);
    if (dp != NULL)
        dp->funcB();
    else
        p->funcA();
}

void funcD(Base* p)
{
    Derived *dp = NULL;
    debug("in funcD", "");
    debug("type(*p):", typeid(*p).name());
    debug("typeid(Derived):", typeid(Derived).name());
    if (typeid(*p) == typeid(Derived))
    {
        dp = static_cast<Derived*>(p);
        dp->funcB();
    }
    else
        p->funcA();
}


int main()
{
    Base *cp = new Derived();
    debug("cp is a pointer to Derived object", "")
    debug("typeid(cp).name(): ", typeid(cp).name());
    debug("typeid(*cp).name(): ", typeid(*cp).name());
    funcD(cp);
    funcC(cp);
    Base *dp = new Base();
    debug("dp is a pointer to Base object", "")
    debug("typeid(dp).name(): ", typeid(dp).name());
    debug("typeid(*dp).name(): ", typeid(*dp).name());
    funcC(dp);
    funcD(dp);
    print("Hello world!");
    return 0;
}
