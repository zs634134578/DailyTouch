#include <iostream>
#include <vector>

class Solution
{
public:
    bool canJump(std::vector<int>& nums) {
        int len = nums.size();
        if (len == 0 || len == 1)
        {
            return true;
        }
        int curDistance = 0;
        int nextDistance = 0;
        int result = false;
        for (int index = 0; index < len; ++index)
        {
            if (curDistance < index)
            {
                curDistance = nextDistance;
                if (curDistance >= len - 1)
                {
                    result = true;
                    break;
                }
            }
            nextDistance = index + nums[index] > nextDistance ? index + nums[index] : nextDistance;
            // not step forward
            if (nextDistance == index)
            {
                break;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    {
        int arr[] = {2,3,1,1,4};
        std::vector<int> nums(arr, arr + 5);
        bool result = solution.canJump(nums);
        std::cout << result << std::endl;
    }
    {
        int arr[] = {3, 2, 1, 0, 4};
        std::vector<int> nums(arr, arr + 5);
        bool result = solution.canJump(nums);
        std::cout << result << std::endl;
    }
    return 0;
}
