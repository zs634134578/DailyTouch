#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<std::string> > partition(std::string s) {
        std::vector<std::vector<std::string> > results;
        std::vector<std::string> res;
        dfs(s, 0, res, results);
        return results;
    }
private:
    void dfs(std::string& s, int startIndex,
            std::vector<std::string> res,
            std::vector<std::vector<std::string> >& results)
    {
        if (startIndex >= s.length())
        {
            results.push_back(res);
        }
        for (int i = startIndex; i < s.length(); ++i)
        {
            int l = startIndex;
            int r = i;
            while (l <= r && s[l] == s[r]) ++l, --r;
            if (l >= r)
            {
                res.push_back(s.substr(startIndex, i - startIndex + 1));
                dfs(s, i + 1, res, results);
                res.pop_back();
            }
        }
    }
};

int main()
{
    return 0;
}
