/*
 * 测试析构函数可以是内联函数吗
 */

#include <iostream>

using namespace std;

class A
{
public:
    A() {}
    inline ~A() 
    {
        std::cout << "inline destructor" << std::endl;
    }
};

int main()
{
    A* a = new A();
    delete a;
    return 0;
}
