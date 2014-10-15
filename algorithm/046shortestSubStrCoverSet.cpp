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
    char* shortestSubStr(char* str, char* destSet)
    {
        char* result = new char[10];
        int strLen = strlen(str);
        int destLen = strlen(destSet);
        
        // temp array to record all char in set
        int destArray[256] = {0};
        // destArray['a'] = 1 if 'a' in destSet
        for(int i = 0; i < destLen; i++)
            destArray[destSet[i]] = 1;
        
        char* front, *rear;
        // temp array to record which chars appear in substring  from front to rear
        int strArray[256] = {0};
        // appearNum to record how many chars appear in substring
        int appearNum = 0;
        int shortestLen = 0;
        char *resultFront, *resultRear;
        
        for (front = rear = str;front <= rear;) 
        {
            if (front == str && rear == str)
            {
                if (destArray[*front])
                {
                    debug("start:", *front);
                    strArray[*front] = 1;
                    appearNum++;
                }
            }
            if(appearNum < destLen && *rear!='\0')
            {
                rear++;
                if (destArray[*rear] && !strArray[*rear]) 
                {
                    strArray[*rear] = 1;
                    appearNum++;
                }
            }
            else
            {
                debug("appearNum:", appearNum);
                debug("destLen:", destLen);
                if (*rear == '\0' && front-rear+1 < destLen)
                {
                    debug("rear reach end", ""); 
                    debug("front;", *front);
                    break;
                }
                if (destArray[*front])
                {
                    strArray[*front] = 0;
                    appearNum--;
                }
                front++;
            }
            
            if (appearNum == destLen)
            {
                int curLen = rear - front + 1;
                if (shortestLen == 0 || curLen < shortestLen)
                {
                    shortestLen = curLen;
                    resultFront = front;
                    resultRear = rear;
                }
            }
        }
        debug("appearNum:", appearNum);
        debug("resultFront:", *resultFront);
        debug("resultRear:", *resultRear);
        for(; resultFront <= resultRear; resultFront++)
            std::cout << *resultFront;
        std::cout << std::endl;
        return resultFront;
    }

};
int main()
{
    char str[10] = "adbcaabcx";
    char strSet[4] = "abc";
    Solution* solver = new Solution();
    char* result;
    result = solver->shortestSubStr(str, strSet);
    print("Hello world!");
    return 0;
}
