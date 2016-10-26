/*
 * Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.
 *
 * Return all such possible sentences.
 *
 * For example, given
 * s = "catsanddog",
 * dict = ["cat", "cats", "and", "sand", "dog"].
 *
 * A solution is ["cats and dog", "cat sand dog"].
 */

#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include "common.h"

using namespace std;

class Solution
{
    public:
        vector<string> wordBreak(string s, unordered_set<string> &dict)
        {
            vector<string> result;
            if ( s.length() < 1)
                return result;
            //bool flag = false; 
            for ( unsigned int i = 0; i <= s.length(); i++)
            {
                string tmpstr = s.substr(0, i);
  //              debug("tmpstr: ", tmpstr);
                unordered_set<string>::iterator it = dict.find(tmpstr);
                vector<string> tmpvec;
                if ( it != dict.end())
                {
 //                   debug("after find: ", *it);
                    result.push_back(tmpstr);
                    if (tmpstr.length() == s.length())
//                    debug("find: ", tmpstr);
                    tmpvec= wordBreak(s.substr(i), dict);
                    if ( !tmpvec.empty())
                        result.insert(result.end(), tmpvec.begin(), tmpvec.end());
                }
            }
            return result;
        }

};

int main()
{
    unordered_set<string> dict({"cat", "cats", "and", "sand", "dog"});
    std::string s("catsanddog");
    Solution* solver = new Solution();
    vector<string> result = solver->wordBreak(s, dict);
    printVec<string>(result);
    debug("result size: ", result.size());
    debug("", "Hello world");
    return 0;
}
