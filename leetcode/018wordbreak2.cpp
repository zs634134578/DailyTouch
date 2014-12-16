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


    vector<string> getResultFromDp(string s, vector<bool> dp, int start)
    {
        vector<string> result;
        //for(int i = 0; i < dp.size(); )
        //{
            string tmpResult;
            int k = 0;
            for(int j = k+1; j < dp.size(); j++)
            {
                if( dp[j] == 1)
                {
                    tmpResult += " ";
                    tmpResult += s.substr(k, j-k);
                    debug("tmpResult:", tmpResult);
                    k = j;
                }
            }
            result.push_back(tmpResult);
        //}
        return result;

    }
    
    vector<string> wordBreak(string s, unordered_set<string> &dict) /* Bottom up dp */ { int len = s.length();
        vector<bool> dp(len+1, false);
        dp[len] = true;

        for( int i = len-1; i >=0; i-- )
            for( int j = i; j < len; j++)
            {
                string tmpStr = s.substr(i, j-i+1);
                debug("tmpStr:", tmpStr);
                if ( dict.find(tmpStr)!=dict.end() && dp[j+1])
                {
                    dp[i] = true;
                    break;
                }
            }
        printVec(dp);

        /*
         * handle dp[] to find valid sentences
         */
        vector<string> result;
        result = getResultFromDp(s, dp, 0);
        return result;
    }

};

void printVec(vector<bool> &bvec)
{
    for(vector<bool>::iterator it = bvec.begin();
        it != bvec.end();
        it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void testcase1(Solution* solver)
{
    debug("----testcase1----", "");
    string s("leetcode");
    unordered_set<string> dict({"leet", "code"});

    for(const string& x : dict)
        debug("each element:", x);

    solver->wordBreak(s, dict);
    debug("----end testcase1----", "\n");
}

void testcase2(Solution* solver)
{
    debug("----testcase2----", "");
    string s("abcd");
    unordered_set<string> dict({"a", "abc", "b", "cd"});

    for(const string& x : dict)
        debug("each element:", x);

    solver->wordBreak(s, dict);
    debug("----end testcase2----", "\n");
}

void testcase3(Solution* solver)
{
    debug("----testcase3----", "");
    string s("catsanddog");
    unordered_set<string> dict({"cat", "cats", "and", "sand", "dog"});

    solver->wordBreak(s, dict);
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
