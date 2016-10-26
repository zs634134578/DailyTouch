/*
 * 求连续子数组的最大和
 *
 * 动态规划的思想：
 *
 * 算法：
 * f(i)表示以nums[i]结尾的子数组
 *     f(i) = {
 *				nums[i],   f(i-1) <= 0
 *				f(i-1) + nums[i],  f(i-1) > 0
 *			  }
 *	通常，利用动态规划的思想，得到递归公式
 *	用循环的方式编码实现。
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums);
};

int Solution::maxSubArray(std::vector<int>& nums)
{
	if (nums.size() == 0)
	{
		return 0;
	}
	int curSum = 0;
	int maxSum = 0;
	for (std::vector<int>::const_iterator it = nums.begin();
		 it != nums.end();
		 ++it)
	{
		curSum += *it;
		if (curSum > maxSum)
		{
			maxSum = curSum;
		}
		else if (curSum < 0)
		{
			curSum = 0;
		}
	}
	return maxSum;
}

int main()
{
	Solution solution;
	int numsArray[] = {1, -2, 3, 10, -4, 7, 2, -5};
	std::vector<int> nums(numsArray, numsArray + 8);
	std::cout << nums.size() << std::endl;
	std::cout << solution.maxSubArray(nums) << std::endl;
	return 0;
}
