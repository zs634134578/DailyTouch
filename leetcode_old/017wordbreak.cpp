/*
 *
 */

#include "common.h"
#include <unordered_set>


using namespace std;

#define debug(x, y) std::cout << "(debug)" << x << y << std::endl;
#define print(x) std::cout << x << std::endl;

class Solution
{
public:
    bool wordBreak(string s, unordered_set<string> &dict)
    /* Bottom up dp
     */
    {
        int len  = s.length();
        vector<bool> dp(len+1, false);
        dp[len] = true;
        
        for ( int i = len-1; i >= 0; i--)
            for ( int j = i; j < len; j++)
            {
                string str = s.substr(i, j - i + 1);
                debug("i:", i);
                debug("j:", j);
                debug("substr: ", str);
                if ( dict.find(str) != dict.end() && dp[j+1])
                {
                    dp[i] = true;
                    break;
                }
            }
        for(vector<bool>::iterator it = dp.begin();
            it != dp.end();
            it++)
            std::cout << *it << " ";
        std::cout << std::endl;
        return dp[0];

    }

    bool wordBreak1(string s, unordered_set<string> &dict)
    /*
     * wrong anwser
     * */
    {
        for(int start = 0, len = 1; len <= s.length(); len++)
        {
            //debug("substr:", s.substr(start, end));
            if ( dict.count(s.substr(start, len)) > 0)
            {
                debug("true str: ", s.substr(start,len));
                debug("start: ", start);
                debug("len:", len);
                debug("s.length:", s.length());
                dict.erase(s.substr(start, len));
                if ( start+len  == s.length())
                    return true;
                else
                {
                    start += len;
                    len = 0;
                }
            }
        }
        return false;
    }

};

void testcase1(Solution* solver)
{
    debug("----testcase1----", "");
    string s("leetcode");
    unordered_set<string> dict({"leet", "code"});

    for(const string& x : dict)
        debug("each element:", x);

    if(solver->wordBreak(s, dict))
    {
        print("true");
    }
    else
        print("false");
    
    debug("----end testcase1----", "\n");
}

void testcase2(Solution* solver)
{
    debug("----testcase2----", "");
    string s("abcd");
    unordered_set<string> dict({"a", "abc", "b", "cd"});

    for(const string& x : dict)
        debug("each element:", x);

    if(solver->wordBreak(s, dict))
    {
        print("true");
    }
    else
        print("false");
    
    debug("----end testcase2----", "\n");
}

void testcase3(Solution* solver)
{
    debug("----testcase3----", "");
    string s("aaaaaaa");
    unordered_set<string> dict({"aaaa", "aaa"});

    if(solver->wordBreak(s, dict))
    {
        print("true");
    }
    else
        print("false");
    
    debug("----end testcase3----", "\n");
}

int main()
{
    Solution* solver = new Solution();
    testcase1(solver);
    testcase2(solver);
    testcase3(solver);
    print("Hello world!");
    return 0;
}
