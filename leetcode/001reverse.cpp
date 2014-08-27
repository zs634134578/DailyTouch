#include <iostream>
#include <string.h>
#include <list>

using namespace std;

#define debug(s) std::cout << s << std::endl;

class Solution 
{
public:
    Solution() {};
    
    void reverseWords(string &s) {
        
        preHandle(s);

        if ( s.length() == 0 || s.length() == 1 )
            return;
        
        int start, end, index;
        int len = s.length();
        
        start = 0;
        end = 0;
        index = 0;
        while( end < len )
        {
            if ( s[end+1] != ' ' && end+1 < len )
                end++;
            else
            {
                reversePart(s, start, end++);
                while( s[end] == ' ' && end < len-1)
                    end++;
                start = end;
            }
        }
        reversePart(s, 0, len-1);
    }

    void preHandle(string& s) {
        // 去除两端空格
        const string spc = " ";
        s.erase(s.find_last_not_of(spc) + 1);
        s.erase(0, s.find_first_not_of(spc));
        // 替换字符串中多个空格为一个空格
        int index = 0;
        int start = 0;
        while( ( index = s.find(' ', index )) != -1  ) {
                index++;
                while ( s[index] == ' ') {
                s.erase(index, 1);
            }
        }
    }

    void reversePart(string& s, int start, int end) {
        
        if ( start >= end )
            return;

        int i, j;
        char tmp;
        for( i = start, j = end; i < j; i++, j-- )
        {
           tmp = s[i];
           s[i] = s[j];
           s[j] = tmp;
        }
        return;
    }

    ~Solution(){};
};

int main()
{
    list<string>* strlist = new list<string>();
    strlist->push_back("the sky is blue");
    strlist->push_back("  the sky is blue    ");
    strlist->push_back("   ");
    strlist->push_back("the   sky    is     blue");
    for ( list<string>::iterator it = strlist->begin(); it != strlist->end(); it++ )
    {
        Solution* solver = new Solution();
        std::cout << "before reverse:'" << *it << "'" << std::endl; 
        solver->reverseWords(*it);
        std::cout << "after reverse:'" << *it << "'" << std::endl << std::endl;
    }
    return 0;
}
