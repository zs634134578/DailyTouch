#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <int Value>
void add(int& elem)
{
    elem += Value;
}

class Adder
{
public:
    Adder(int value)
    {
        this->value = value;
    }

    int operator()(int& base)
    {
      return  base += this->value;
    }
private:
    int value;
};

vector<int> f1()
{
    vector<int> coll(0, 11);
    //...
    Adder adder(21);
    int a = 11;
    std::cout <<  adder(a) << std::endl;
//    for_each(coll.begin(), coll.end(), Adder(10));
    return coll;
}

int main()
{
    vector<int> iv;
    iv = f1();
    for(vector<int>::iterator it = iv.begin();
        it != iv.end();
        it++)
        std::cout << *it << std::endl;
    return 0;
}
