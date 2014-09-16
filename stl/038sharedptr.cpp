#include <iostream>
#include <tr1/memory>
using namespace std;

#define debug(x, y)  std::cout << "(debug)" << x << " " << y << std::endl;

class A{
public:
    A(){std::cout << "A constructor" << std::endl;}
    virtual ~A() {std::cout << "A destructor" << std::endl;}
};
class B:public A{
public:
    B() {std::cout << "B constructor" << std::endl;} 
    ~B() {std::cout << "B destructor" << std::endl;}
};

int main()
{
    A* a = new A();
    delete a;
    a = NULL;

//    B* b = new B();
    std::tr1::shared_ptr<B> spt(new B());
    return 0;
}
