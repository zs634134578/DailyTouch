/*
 *
 */

#include <iostream>
#include <string.h>

using namespace std;

#define debug(x, y) std::cout << "(debug)" << x << y << std::endl;
#define print(x) std::cout << x << std::endl;

class Solution
{
public:
    void kmp(char* srcStr, char* destStr)
    {

    }

    int* getPMT(char* destStr)
    {
        int len = strlen(destStr);
        int* pmt = new int[len];
        
        return pmt;
    }
};
int main()
{
    char srcStr[22] = "BBCABCDABABCDABCDABDE";
    char destStr[8] = "ABCDABD";
    Solution* solver = new Solution();
    solver->kmp(srcStr, destStr);
    print("Hello world!");
    return 0;
}
