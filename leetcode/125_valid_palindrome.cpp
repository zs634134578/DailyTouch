#include <iostream>
#include <ctype.h>


class Solution
{
public:
    bool isPalindrome(std::string s)
    {
        bool ret = true;
        if (s.size() == 0)
        {
            ret = true;
        }
        for (int i = 0, j = s.size() - 1;
             i <= j;)
        {
            if (!isalnum(s[i]))
            {
                ++i;
                continue;
            }
            if (!isalnum(s[j]))
            {
                --j;
                continue;
            }
            if (tolower(s[i]) == tolower(s[j]))
            {
                ++i;
                --j;
                continue;
            }
            else
            {
                ret = false;
                break;
            }
        }
        return ret;
    }

};

int main()
{
    Solution solution;
    std::cout << solution.isPalindrome("aA") << std::endl;;
    return 0;
}
