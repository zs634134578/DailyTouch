#include <iostream>
#include <vector>

class Solution
{
public:
    int partialMinimum(const std::vector<int>& nums)
    {
        int size = nums.size();
        if (size == 0)
        {
            return -1;
        }
        if (size == 1 || nums[0] < nums[1])
        {
            return 0;
        }
        if (nums[size - 1] < nums[size - 2])
        {
            return size - 1;
        }
        int left = 1;
        int right = size - 2;
        int result = -1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid - 1])
            {
                right = mid - 1;
            }
            else if (nums[mid] > nums[mid + 1])
            {
                left = mid + 1;
            }
            else
            {
                result = mid;
                break;
            }
        }
        return result;
    }
};

int main()
{
    std::vector<int> nums = {9, 8, 7, 5, 6, 4, 3, 2, 10};
    Solution solution;
    std::cout << solution.partialMinimum(nums) << std::endl;
    return 0;
}
