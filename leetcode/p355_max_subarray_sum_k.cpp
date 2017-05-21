#include <iostream>
#include <vector>
#include <map>

class Solution
{
public:
    int maxSubarraySumK(std::vector<int>& nums, int target)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        int maxLen = 0;
        std::map<int, int> sum2IndexMap;
        sum2IndexMap[0] = -1;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum = sum + nums[i];
            auto iter = sum2IndexMap.find(sum - target);
            if (iter != sum2IndexMap.end())
            {
                maxLen = std::max(i - iter->second, maxLen);
            }
            if (sum2IndexMap.find(sum) == sum2IndexMap.end())
            {
                sum2IndexMap.insert(std::make_pair(sum, i));
            }
        }
        return maxLen;
    }
};

int main()
{
    Solution solution;
    std::vector<int> nums = {1, 2, 1, -1, 1, -1, 0, 1};
    std::cout << solution.maxSubarraySumK(nums, 3) << std::endl;
}
