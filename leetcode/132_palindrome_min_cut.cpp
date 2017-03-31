#include <iostream>
#include <stdint.h>

class Solution {

public:
    int minCut(std::string s) {
        int len = s.length();
        int minCut = 0;
        bool isPalindrome[len][len] = {false};
        int dp[len + 1] = {INT32_MAX};
        dp[len] = -1;
        for (int leftIndex = len - 1; leftIndex >= 0; --leftIndex)
        {
            for (int midIndex = leftIndex; midIndex <= len - 1; ++midIndex)
            {
                if ((midIndex - leftIndex < 2 || isPalindrome[leftIndex + 1][midIndex -1])
                   && s[leftIndex] == s[midIndex])
                {
                    isPalindrome[leftIndex][midIndex] = true;
                    dp[leftIndex] = std::min(dp[midIndex + 1] + 1, dp[leftIndex]);
                }
            }
            std::cout << leftIndex << ": " << dp[leftIndex] << std::endl;
        }
        return dp[0];
    }

};

int main()
{
    Solution solution;
    std::cout << solution.minCut("aabc") << std::endl;
}
