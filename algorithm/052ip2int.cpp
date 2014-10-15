/*
 * ip地址转成int型
 */

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

#define debug(x, y) std::cout << "(debug)" << x << y << std::endl;
#define print(x) std::cout << x << std::endl;

class Solution
{
public:
    Solution(char* srcIp, int len)
    {
        this->srcIp = srcIp;
        this->len = len;
    }

    int ip2Int()
    {
        int destArr[4];
        this->ip2IntArr(destArr,4);
        unsigned int result = destArr[0];
        for(int i = 1; i < 4; i++)
        {
            result <<= 8;
            result |= destArr[i];
            printf("destArr[index]:%x\n", destArr[i]);
            printf("result:%x\n", result);

        }
        debug("result:", result);
        
    }

    void ip2IntArr(int* destArr, int len)
    {
        if (destArr == NULL || len < 0)
            // error log
            return;
        
        char* start, *end;
        int index = 0; // for destArr
        for(start = end = this->srcIp;
            end <= srcIp + this->len +1;)
        {
            if (*end == '.' || *end == '\0')
            {
                char tmpStr[4] = {0};
                char* l = start;
                for(int i=0; l < end; i++, l++)
                {
                    tmpStr[i] = *l;
                }
                destArr[index++] = atoi(tmpStr);
                debug("destArr[index]:", destArr[index-1]);
                end++;
                start = end;
            }
            else 
                end++;
        }
    }

private:
    char* srcIp;
    int len;
};
int main()
{
    char srcIp[] = "192.168.0.1";
    Solution* solver = new Solution(srcIp, strlen(srcIp)-1);
    solver->ip2Int();
    
    
    print("Hello world!");
    return 0;
}
