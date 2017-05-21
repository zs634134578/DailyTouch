#include <iostream>
#include <vector>
#include <map>

class Solution
{
public:
    int maxSubarraySumLessOrEqualK(std::vector<int>& nums, int target)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        std::vector<int> sumArray;
        int sum = 0;
        int maxLen = 0;
        sumArray.push_back(sum);
        for (int cur = 0; cur < nums.size(); ++cur)
        {
            sum += nums[cur];
            int start = binarySearch(sumArray, sum - target);
            int len = start == -1 ? 0 : cur - start + 1;
            maxLen = std::max(maxLen, len);
            int toPush = std::max(sum, sumArray.back());
            sumArray.push_back(toPush);
        }
        return maxLen;
    }
private:
    // find element >= key
    int binarySearch(std::vector<int> sumArray, int key)
    {
        int left = 0;
        int right= sumArray.size() - 1;
        int mid = -1;
        while (left <= right)
        {
            mid = (right + left) / 2;
            if (sumArray[mid] >= key)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left < sumArray.size() ? left : -1;
    }
};

int main()
{
    Solution solution;
    std::vector<int> nums = {3, -2, -4, 0, 6};
    std::cout << solution.maxSubarraySumLessOrEqualK(nums, 2) << std::endl;
}
