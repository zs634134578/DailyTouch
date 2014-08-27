#include <iostream>
#include <set>
#include <string>
#include <ostream>
#include <algorithm>
#include <iterator>

using namespace std;

void print(set<string*> ssp)
{
    for(set<string*>::const_iterator it=ssp.begin(); it != ssp.end();it++)
    {
        std::cout << **it << std::endl;
    }
}

void print2(set<string*> ssp)
{
    copy(ssp.begin(), ssp.end(), ostream_iterator<string*>(std::cout, "\n"));    
}

void pout(const string* ps)
{
    std::cout << *ps << std::endl;
}

void print3(set<string*> ssp)
{
    for_each(ssp.begin(), ssp.end(), pout);
}

void test1()
{
    set<string*> ssp; 
    string* a = new string("Lemur");
    ssp.insert(new string("Anteater"));
    ssp.insert(new string("Wombat"));
    ssp.insert(a);
    ssp.insert(new string("Penguin"));
    print3(ssp);
    set<string*>::iterator i = ssp.find(a);
    if (i != ssp.end())
    {
        ssp.erase(i++);
    }
    std::cout << "\n";
    print3(ssp);
    std::cout << "\n";
    std::cout << **i << std::endl;
    
}

int main()
{
    test1();
    std::cout << "Hello world!" << std::endl;
    return 0;
}

