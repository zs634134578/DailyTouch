/*
 * 问题描述：
 *     给定一个字符串S = a1a2a3...an，要求找出其最长回文子串
 *         例如：对于子串S=abcdcbeba，其回文子串有：bcdcb, cdc, beb， 最长回文子串为bcdcb
 *
 */


#include <iostream>
#include <memory.h>

using namespace std;

#define debug(x,y) std::cout << "(debug)" << x << y << std::endl;

class LPSer
{
public:
    LPSer(char* str, int len)
    {
       this->str = str;
       this->len = len;
    }

    void findLPS()
    {
        if (this->str == NULL)
            return ;
        if (len <= 0)
            return ;
        bool p[this->len][this->len]; 
        memset(p,false, sizeof(p));
        int i, j;
        int longestBegin;
        int maxlen;
        for(i=0; i < len; i++)
            p[i][i] = true;

        for(i=0; i < len-1; i++)
        {
            if(this->str[i] == this->str[i+1])
            {
                p[i][i+1] = true;
                longestBegin = i;
                maxlen = 2;
            }
        }

        int width;
        for(width = 3; width <= len; width++)
        {
            for(i=0; i < this->len-width+1 ; i++)
            {
                j = i + width - 1;
                if(this->str[i] == this->str[j] && p[i+1][j-1])
                {
                    p[i][j] = true;
                    longestBegin = i;
                    maxlen = j-i+1;
                    debug("i:", i);
                    debug("j:", j);
                    debug("longestBegin:", longestBegin);
                    debug("maxlen:", maxlen);
                }
            }
            
        }
        std::cout << "longestBegin:" << longestBegin
            << "; maxlen:" << maxlen << std::endl;
    }
private:
    char* str;
    int len;
};

int main()
{
    char a[11] = "abcddcbeba";
    LPSer* lpser = new LPSer(a, 10);
    lpser->findLPS();
    debug("Hello world!", "")
    return 0;
}
