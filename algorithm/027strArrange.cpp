/*
 * 问题描述：
 *     输入一个字符串，打印出该字符串中字符的所有排列。
 *         例如：
 *             输入：abc    
 *                 输出：abc acb bac bca cab cba
 */

#include <iostream>
#include <unistd.h>
#include <cstdlib>
using namespace std;

#define debug(x, y) std::cout << "debug: " << x << " " << y <<  std::endl;

class Solution
{
public:
    void strArrange(char* str, int len)
    {
        if(str == NULL || len <= 0)
            return ;
        if (len == 1)
            std::cout << str[0] << std::endl;
        arrange(str, str);    
    }

    void arrange(char* str, char* strBegin)
    {
        if(*strBegin == '\0')
            std::cout << str << std::endl;
        else
        {
            for(char* pCh = strBegin; *pCh != '\0'; pCh++)
            {
                char tmp = *pCh;
                *pCh = *strBegin;
                *strBegin = tmp;

                arrange(str, strBegin+1);

                tmp = *pCh;
                *pCh = *strBegin;
                *strBegin = tmp;
            }
        }
    }

    void group(char* str, int len)
    {
       if (str == NULL) 
           return ;
       do_group(str, str+1);
    }

    void do_group(char* str, char* choice)
    {
        if(*choice == '\0')
        {
            std::cout << str << std::endl;
            return;
        }

        for(char* index = str; index != choice; index++)
        {
            if(index == str)
                printleft(str, choice);
            for(char* index2 = choice; *index2 != '\0'; index2++)
            {
                char tmp = *index2;
                *index2 = *index;
                *index = tmp; 
                printleft(str, choice);
                tmp = *index2;
                *index2 = *index;
                *index = tmp;
            }
        }
        do_group(str, choice+1);
    }

    void printleft(char* str, char* choice)
    {
        for(char* index = str; index != choice; index++)
        {
            std::cout << *index ;
        }
        std::cout << std::endl;
    }
    

};

int main()
{
    char str[10] = "abc";
    Solution* solver = new Solution();
    solver->group(str, 9);
    std::cout << "Hello world!" << std::endl;
    return 0;
}
