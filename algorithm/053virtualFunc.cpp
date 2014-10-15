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
    void f()
    {
        std::cout << "base f." << std::endl;
    }

};

class SubSolution: public Solution
{
public:
    void f()
    {
        std::cout << "sub f." << std::endl;
    }
};

int main()
{
    SubSolution solver ;
    Solution* p = &solver;
    p->f();
    SubSolution* subp = (SubSolution*)p;
    subp->f();
    print("Hello world!");
    return 0;
}
