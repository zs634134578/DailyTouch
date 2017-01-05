#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

#define DEBUG(key, info) std::cout << "DEBUG: " << key << " - " << info << std::endl;

#define PrintVec(info, result) \
    std::cout << "print vector: " << info << std::endl; \
    { \
        for (std::vector<std::string>::const_iterator it = result.begin(); \
                it != result.end(); \
                ++it) \
        { \
            std::cout << "\t" << *it << std::endl; \
        } \
    } 

class Solution {
private:
    std::unordered_map<std::string, std::vector<std::string> > m;
    std::vector<std::string> combine(std::string word,
                                     std::vector<std::string> prev)
    {
        for (int i = 0; i < prev.size(); ++i)
        {
            prev[i] += " " + word;
        }
        return prev;
    }
public:
    std::vector<std::string> wordBreak(std::string s, std::unordered_set<std::string>& dict) {
        if (m.count(s))
        {
            DEBUG("match!", s);
            return m[s];
        }
        std::vector<std::string> result;
        if (dict.count(s))
        {
            result.push_back(s);
        }
        for (int i = 1; i < s.size(); ++i)
        {
            std::string word = s.substr(i);
            DEBUG("word", word);
            if (dict.count(word))
            {
                std::string rem = s.substr(0, i);
                DEBUG("rem", rem);
                std::vector<std::string> prev = combine(word, wordBreak(rem, dict));
                result.insert(result.end(), prev.begin(), prev.end());
            }
        }
        DEBUG("s", s);
        PrintVec(s, result);
        m[s] = result;
        return result;
    }

};

int main()
{
    //std::string s("catsanddogdog");
    //std::unordered_set<std::string> dict = {"cat", "cats", "and", "sand", "dog"};
    std::string s("aaaaaaaa");
    std::unordered_set<std::string> dict = {"a", "aa", "aaa", "aaaa", "aaaaa"};
    Solution solution;
    std::vector<std::string> result = solution.wordBreak(s, dict);
    for (std::vector<std::string>::const_iterator it = result.begin();
         it != result.end();
         ++it)
    {
        std::cout << *it << std::endl;
    }
    return 0;
}
