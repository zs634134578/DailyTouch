/*
 * 测试，在构造函数中调用虚函数是否会报错
 */

#include<iostream>

using namespace std;

#define debug(x,y) std::cout << "(debug)" << x << y << std::endl;

class Base
{
    public:
        Base() { foo(); }
        virtual void foo() { std::cout << "Base constructor called" << std::endl; }
};

class Child:public Base
{
    public:
        Child() {foo();}
        virtual void foo() { std::cout << "Child constructor called" << std::endl;}
};
int main()
{
    debug("Hello world", "");
    Base* base = new Base();
//    Child* chd = new Child();
    return 0;
}
