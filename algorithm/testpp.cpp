/*
 *
 */

#include <iostream>
#include <string.h>
#include <typeinfo>
using namespace std;

#define debug(x, y) std::cout << "(debug)" << x << y << std::endl;
#define print(x) std::cout << x << std::endl;

class Solution
{
public:
    void test()
    {
        int a[10] = {9};
        int* p = a;
        int* q = a+9;

        while(*p++ == * q++)
        {
            std::cout << static_cast<int>(p - a) << std::endl;
        }
            std::cout << static_cast<int>(p - a) << std::endl;
            std::cout << static_cast<int>(q - a) << std::endl;
    }
    void test1()
    {
        std::cout << strcmp("abc", "abc") << std::endl;
    }

};
int main()
{
    Solution* solver = new Solution();
    solver->test1();
    char a[8];
    std::cout << typeid(a).name() << std::endl;
    print("Hello world!");
    return 0;
}
