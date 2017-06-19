#include <iostream>
#include <vector>
#include "../common/array.h"

class Solution
{
public:
    void sort(std::vector<int>& nums)
    {
        if (nums.size() == 0)
        {
            return;
        }
        int left = -1;
        int right = nums.size();
        for (int i = 0; i < right;)
        {
            if (nums[i] == 1) { i++; continue; }
            if (nums[i] == 0) { swap(nums, ++left, i++); continue; }
            if (nums[i] == 2) { swap(nums, --right, i); continue; }
        }
    }
private:
    void swap(std::vector<int>& nums, int i, int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};

int main()
{
    Solution solution;
    std::vector<int> nums = {1, 2, 0, 0, 2, 1, 1, 0, 2};
    solution.sort(nums);
    common::array::print(nums);
}
