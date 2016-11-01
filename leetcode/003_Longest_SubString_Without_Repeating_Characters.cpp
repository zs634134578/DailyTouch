#include <iostream>
#include <string>

class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        if (s.empty())
        {
            return 0;
        }
        int subStrStartIndex = 0;
        int subStrEndIndex = 0;
        int maxSubStrLength = 1;
        int subStrNextIndex = 0;
        while (subStrEndIndex < s.length() - 1)
        {
            if (++subStrNextIndex == s.length())
            {
                break;
            }
            int repeatIndex = findRepeatCharacter(s, subStrStartIndex, 
                                                  subStrEndIndex,
                                                  subStrNextIndex);
            if (repeatIndex == -1)
            {
                // there is no repeat charactor in pre substring
                subStrEndIndex = subStrNextIndex;
                int curSubStrLength = subStrEndIndex - subStrStartIndex + 1;
                if (maxSubStrLength < curSubStrLength)
                {
                    maxSubStrLength = curSubStrLength;
                }
            }
            else
            {
                subStrStartIndex = repeatIndex + 1;
                subStrEndIndex = subStrNextIndex;
            }
        }
        return maxSubStrLength;
    }
private:
    int findRepeatCharacter(const std::string& s,
                            int startIndex,
                            int endIndex,
                            int nextIndex)
    {
        for (int searchIndex = startIndex;
             searchIndex <= endIndex;
             ++searchIndex)
        {
            if (s[searchIndex] == s[nextIndex])
            {
                return searchIndex;
            }
        }
        return -1;
    }
};

int main()
{
    Solution solution;
    std::cout << "abcabcbb: " << solution.lengthOfLongestSubstring("abcabcbb") << std::endl;
    std::cout << "bbbbbb: " << solution.lengthOfLongestSubstring("bbbbbb") << std::endl;
    std::cout << "pwwkew: " << solution.lengthOfLongestSubstring("pwwkew") << std::endl;
    return 0;
}
