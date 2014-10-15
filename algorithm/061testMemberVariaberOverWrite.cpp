/*
 *
 */

#include <iostream>

using namespace std;

#define debug(x, y) std::cout << "(debug)" << x << y << std::endl;
#define print(x) std::cout << x << std::endl;

class Solution
{
public:
    Solution() {
        a = 1;
    }
    void printA()
    {
        debug("Base A a=", a);
    }
    int a;
};

class B: public Solution
{
public:
    B()
    {
        a = 2;
    }
    int a;
};

int main()
{
    B b;
    b.printA();
    debug("B.a:", b.a);

    print("Hello world!");
    return 0;
}
