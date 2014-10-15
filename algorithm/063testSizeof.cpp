/*
 *
 */

#include <iostream>
#include<string>

using namespace std;

#define debug(x, y) std::cout << "(debug)" << x << y << std::endl;
#define print(x) std::cout << x << std::endl;

class Solution
{

};
int main()
{
    Solution* solver = new Solution();
    debug("sizeof(string):", sizeof(string));
    string str("1234567");
    debug("sizeof(str)", sizeof(str));
    print("Hello world!");
    return 0;
}
