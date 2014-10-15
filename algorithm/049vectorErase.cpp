/*
 *
 */

#include <iostream>
#include<vector>
using namespace std;

#define debug(x, y) std::cout << "(debug)" << x << y << std::endl;
#define print(x) std::cout << x << std::endl;

class Solution
{

};
int main()
{
    int a[5] = {1,2,3,3,5};
    vector<int> ivec(a, a+5);
    vector<int>::iterator it;
    for( it = ivec.begin(); it!=ivec.end(); )
    {
        if(*it == 3)
            it = ivec.erase(it);
        else
            it++;
    }


    for( it = ivec.begin(); it!=ivec.end();it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    print("Hello world!");
    return 0;
}
