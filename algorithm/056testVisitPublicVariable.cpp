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

class Base
{
public:
    Base() {
        val = 1;    
    }
    void sayBase()
    {
        std::cout << "Hello Base" << std::endl;
    }
    int val;
};

class Derived: Base
{
public:
    Derived(int i) {
        val = i;
        Base::sayBase();
        debug("Base::val:", Base::val);
    }
    int val;
};

int main()
{

    Base base;
    Derived derived(10);
//    debug("Base::val:", derived.Base::val);
    debug("Derived::val:", derived.val);
    print("Hello world!");
    return 0;
}
