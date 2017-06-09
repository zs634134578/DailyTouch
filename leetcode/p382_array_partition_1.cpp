#include <iostream>
#include <vector>
#include "../common/array.h"

class Solution
{
public:
    void partition(std::vector<int>& nums)
    {
        if (nums.size() <= 1)    
            return;
        int left = 0;
        int right = 1;
        while (right < nums.size())
        {
            if (nums[right] != nums[left])
            {
                left++;
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
            }
            right++;
        }
        return;
    }
};

int main()
{
    Solution solution;
    std::vector<int> nums = {1,2,2,2,3,3,4,5,6,6,7,7,8,8,8,9};
    common::array::print(nums);
    solution.partition(nums);
    common::array::print(nums);
    return 0;
}
