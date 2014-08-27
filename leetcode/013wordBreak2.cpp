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

using namespace std;

#define debug(x, y) std::cout << "(debug)" << x << y << std::endl;

class Solution
{
    public:
        vector<string> wordBreak(string s, unordered_set<string> &dict)
        {
            int len;
            string prefix;
            for(unordered_set<string>::iterator it = dict.begin();
                it != dict.end();
                it++)
            {
                debug("*it:", *it);
                len = (*it).size();
                string::size_type begin;
                begin = s.find(s.c_str(), 0, static_cast<string::size_type>(len));
                debug("begin:", begin);
                if (begin == string::npos);
                    continue;
                prefix = s.substr(0, len-1);
                debug("prefix:", prefix);
                wordBreak(s.substr(len), dict);
            }
            
            debug("s:", s);
            s.find("cats");
            vector<string> sv;
            return sv;
        }

};

int main()
{
    unordered_set<string> dict({"cat", "cats", "and", "sand", "dog"});
    std::string s("catsanddog");
    Solution* solver = new Solution();
    solver->wordBreak(s, dict);
    debug("", "Hello world");
    return 0;
}
