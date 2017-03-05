#include <iostream>

class Solution
{
public:
    int MaxLength(const std::string& str)
    {
        int size = str.size();
        if (size < 2)
        {
            return 0;
        }
        int dp[size] = {0};
        int max = 0;
        for (int i = 0; i < size; ++i)
        {
            if (str[i] == '(')
            {
                dp[i] = 0;
            }
            else
            {
                int pre = i - dp[i - 1] - 1;
                if (pre >= 0 && str[pre] == '(')
                {
                    dp[i] = dp[i - 1] + 2 + (pre - 1 > 0 ? dp[pre - 1] : 0);
                    max = dp[i] > max ? dp[i] : max;
                }
            }
        }
        return max;
    }
};

int main()
{
    Solution solution;
    {
        std::cout << solution.MaxLength("()(())()") << std::endl;
    }
    return 0;
}
