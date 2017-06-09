#include <iostream>
#include <vector>

class Solution
{
public:
    double maxMulti(std::vector<double>& nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        double curMax = nums[0];
        double curMin = nums[0];
        double result = nums[0];
        for (std::vector<double>::iterator cur = nums.begin() + 1; cur < nums.end(); ++cur)
        {
            double cand1 = curMax * *cur;
            double cand2 = curMin * *cur;
            double cand3 = *cur;
            curMax = std::max(cand1, std::max(cand2, cand3));
            curMin = std::min(cand1, std::min(cand2, cand3));
            result = std::max(curMax, result);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    std::vector<double> nums = {-2.5, 4, 0, 3, 0.5, 8, -1};
    std::cout << solution.maxMulti(nums) << std::endl;
}
