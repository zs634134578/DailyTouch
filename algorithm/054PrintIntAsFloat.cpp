/*
 *
 */

#include <iostream>
#include <stdio.h>


using namespace std;

#define debug(x, y) std::cout << "(debug)" << x << y << std::endl;
#define print(x) std::cout << x << std::endl;

#define BIT_MASK(bit_pos) (0x01 << (bit_pos))

class Solution
{
public:
    Solution()
    {
        std::cout << "Solution constructor." << std::endl;
        this->a = 1;
    }
    void sayBase()
    {
        std::cout << "say base" << std::endl;
    }
private:
    int a;

};


class SubSolution:private Solution
{
public:
    void saySub()
    {
        std::cout << "say subsolution, a = "<< a << std::endl;
    }
};
int main()
{
 //   Solution* solver = new Solution();
    //printf("print 5 as float: %f\n", 5);
    //printf("print 5.01 as int %d\n",5.01 );
    int a = 1024;
    int b = a < 2;
    int c = a << 2;
    debug("a = ", a);
    debug("a << 2: ", c);   
    debug("a < 2: ", b  );
    Solution* solution = new Solution();
    SubSolution* subsolution = new SubSolution();
    subsolution->saySub();

    print("Hello world!");
    return 0;
}
