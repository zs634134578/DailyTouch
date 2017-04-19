/*
Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn‘t one, return 0 instead.

Example 1:

Given nums = [1, -1, 5, -2, 3], k = 3,
      return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)

    Example 2:

    Given nums = [-2, -1, 2, 1], k = 1,
    return 2. (because the subarray [-1, 2] sums to 1 and is the longest)

    Follow Up:
    Can you do it in O(n) time?

*/

#include <iostream>
#include <vector>
#include <map>

class Solution
{
public:
    int MaxSubArraySumK(const std::vector<int>& nums, int k)
    {
        if (nums.size() == 0)
        {
            return -1;
        }
        // key: sum of nums[0..pos]
        // value: the earlist pos where sum of nums[0..pos] equals with key
        std::map<int, int> sum2posMap;
        sum2posMap.insert(std::make_pair(0, -1));
        int maxLen = 0;
        int curSum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            curSum += nums[i];
            if (sum2posMap.find(curSum) == sum2posMap.end())
            {
                sum2posMap.insert(std::make_pair(curSum, i));
            }
            auto prevPos = sum2posMap.find(curSum - k);
            if (prevPos != sum2posMap.end())
            {
                maxLen = std::max(maxLen, i - prevPos->second);
            }
        }
        return maxLen;
    }
};


int main()
{
    int arr[5] = {1, -1, 5, -2, 3};
    int k = 3;
    std::vector<int> nums(arr, arr + 5);
    Solution solution;
    std::cout << solution.MaxSubArraySumK(nums, k) << std::endl;
    return 0;
}
