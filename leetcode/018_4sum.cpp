#include <iostream>
#include <algorithm>
#include <vector>

class Solution
{
public:
    std::vector<std::vector<int> > fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int> > results;
        std::vector<int> result;
        result.resize(4);
        std::sort(nums.begin(), nums.end());
        for (std::vector<int>::const_iterator it1 = nums.begin();
             it1 != nums.end();)
        {
            int threeSumTarget = target - *it1;
            for (std::vector<int>::const_iterator it2 = it1 + 1;
                 it2 != nums.end();)
            {
                int twoSumTarget = threeSumTarget - *it2;
                std::vector<int>::const_iterator it3 = it2 + 1;
                std::vector<int>::const_iterator it4 = nums.end() - 1;
                while (it3 < it4)
                {
                    if (*it3 + *it4 < twoSumTarget)
                    {
                        while (++it3 < it4 && *it3 == *(it3 - 1)) continue;
                    }
                    else if (*it3 + *it4 > twoSumTarget)
                    {
                        while (--it4 > it3 && *it4 == *(it4 + 1)) continue;
                    }
                    else
                    {
                        result.clear();
                        results.push_back(result);
                        .push_back(*it1);
                        result.push_back(*it2);
                        result.push_back(*it3);
                        result.push_back(*it4);
                        while (++it3 < it4 && *it3 == *(it3 - 1)) continue;
                        while (--it4 > it3 && *it4 == *(it4 + 1)) continue;
                    }
                }
                while (++it2 != nums.end() && *it2 == *(it2 - 1)) continue;
            }
            while (++it1 != nums.end() && *it1 == *(it1 - 1)) continue;
        }
        return results;
    }
};

int main()
{
    Solution solution;
    int arr[6] = {1, 0, -1, 0, -2, 2};
    std::vector<int> nums(arr, arr + 6);
    solution.fourSum(nums, 0);
    return 0;
}
