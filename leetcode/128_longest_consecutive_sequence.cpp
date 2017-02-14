#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        int len = nums.size();
        int maxLen = 0;
        if (len == 0)
        {
            return 0;
        }
        std::map<int, int> index2LenMap;
        for (int index = 0; index < len; ++index)
        {
            if (index2LenMap.find(nums[index]) != index2LenMap.end())
            {
                continue;
            }
            else
            {
                int curSeqLen = 1;
                int lowNum = nums[index];
                int highNum = nums[index];
                std::map<int, int>::iterator leftIt = index2LenMap.find(nums[index] - 1);
                std::map<int, int>::iterator rightIt = index2LenMap.find(nums[index] + 1);
                if (leftIt != index2LenMap.end())
                {
                    curSeqLen = leftIt->second + curSeqLen;
                    lowNum = nums[index] - leftIt->second;
                }
                if (rightIt != index2LenMap.end())
                {
                    curSeqLen = rightIt->second + curSeqLen;
                    highNum = nums[index] + rightIt->second;
                }
                index2LenMap[nums[index]] = curSeqLen;
                index2LenMap[lowNum] = curSeqLen;
                index2LenMap[highNum] = curSeqLen;
                maxLen = curSeqLen > maxLen ? curSeqLen : maxLen;
            }
        }
        return maxLen;
    }
};

int main()
{
    Solution solution;
    {
        int arr[] = {100, 4, 200, 1, 3, 2};
        std::vector<int> nums(arr, arr + 6);
        std::cout << solution.longestConsecutive(nums) << std::endl;
    }
    return 0;
}

