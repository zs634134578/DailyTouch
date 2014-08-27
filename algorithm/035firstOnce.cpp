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
    char findFirst(char* srcStr)
    {
        if (srcStr == NULL)
            return '\0';
        int strArray[256] = {0};
        char* index = srcStr;
        while(*index != '\0')
        {
            strArray[static_cast<int>(*index)] += 1;
            index++;
        }
        index = srcStr;
        while(*index != '\0')
        {
            if (strArray[static_cast<int>(*index)] == 1)
                break;
            index++;
        }
        return *index;
    }

};
int main()
{
    Solution* solver = new Solution();
    std::string srcStr = "abaccdeff";
    char result = solver->findFirst(const_cast<char*>(srcStr.c_str()));
    print(result);
    print("Hello world!");
    return 0;
}
