#include <iostream>
#include <vector>
#include <limits.h>

class Solution
{
public:
    int majorityNumber(std::vector<int> nums)
    {
        if (nums.size() == 0)
        {
            return INT_MIN;
        }
        int candidate = 0;
        int count = 0;
        for (auto num : nums)
        {
            if (count == 0)
            {
                candidate = num;
                count++;
            }
            else if (candidate == num)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        count = 0;
        for (auto num : nums)
        {
            candidate == num ? count++ : count;
        }
        return count >= nums.size() / 2 ? candidate : INT_MIN;
    }
};

int main()
{
    std::vector<int> nums = {1, 1, 1, 1, 1, 1, 3, 4, 5, 6};
    Solution solution;
    std::cout << solution.majorityNumber(nums) << std::endl;
}
