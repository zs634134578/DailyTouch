#include <iostream>
#include <vector>

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
        {
            return 0;
        }
        // p[i] represents longest subsequence's size with arr[i] as end
        std::vector<int> p;
        p.resize(len);
        int max = 0;
        for (int i = 0; i < len; i++)
        {
            p[i] = 1;
            for (int j = i - 1; j >= 0; --j)
            {
                if (nums[j] < nums[i])
                {
                    p[i] = p[j] + 1 >= p[i] ? p[j] + 1 : p[i];
                }
            }
            max = p[i] > max ? p[i] : max;
        }
        return max;
    }
};

int main()
{
    Solution solution;
    {
        int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
        std::vector<int> nums(arr, arr + 8);
        int result = solution.lengthOfLIS(nums);
        std::cout << result << std::endl;
    }
    {
        int arr[] = {1,3,6,7,9,4,10,5,6};
        std::vector<int> nums(arr, arr + 9);
        int result = solution.lengthOfLIS(nums);
        std::cout << result << std::endl;
    }
    return 0;
}
