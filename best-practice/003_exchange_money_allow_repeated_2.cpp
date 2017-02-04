/*
 * 动态规划 + 空间优化
 */

#include <iostream>
#include <vector>

class Solution
{
public:
	int ExchangeMoney(std::vector<uint32_t>& arr, uint32_t aim);
};

int Solution::ExchangeMoney(std::vector<uint32_t>& arr, uint32_t aim)
{
	if (arr.size() == 0 || aim == 0)
	{
		return 0;
	}
	int arrSize = arr.size();
	int dp[aim + 1]; // updated by line
	dp[0] = 0; // first element is always 0
	for (uint32_t rowIndex = 1; rowIndex < aim + 1; ++rowIndex)
	{
		if (int(rowIndex - arr[0]) >= 0 && dp[rowIndex - arr[0]] != UINT32_MAX)
		{
			dp[rowIndex] = dp[rowIndex - arr[0]] + 1;
		}
		else
		{
			dp[rowIndex] = UINT32_MAX;
		}
	}
	for (uint32_t lineIndex = 1; lineIndex < arrSize; ++lineIndex)
	{
		for (uint32_t rowIndex = 1; rowIndex < aim + 1; ++rowIndex)
		{
			int subCurArrValue = rowIndex - arr[lineIndex];
			uint32_t upValue = dp[rowIndex];
			uint32_t leftValue = UINT32_MAX;
			if (subCurArrValue >= 0 && dp[subCurArrValue] != UINT32_MAX)
			{
				leftValue = dp[subCurArrValue] + 1;
			}
			dp[rowIndex] = leftValue < upValue ? leftValue : upValue;
		}
	}
	return dp[aim] == UINT32_MAX ? -1 : dp[aim];
}

void testcase(Solution& solution, uint32_t* array, int size, uint32_t aim, int expectedResult)
{
	std::vector<uint32_t> arr(array, array + size);
	int result = solution.ExchangeMoney(arr, aim);
	if (result != expectedResult)
	{
		std::cout << "Case Failed! aim: " << aim
				  << ", expectedResult: " << expectedResult
				  << ", result: " << result << std::endl;
	}
	else
	{
		std::cout << "Case Pass!" << std::endl;
	}
}

int main()
{
	Solution solution;
	{
		uint32_t array[3] = {5, 2, 3};
		testcase(solution, array, 3, 20, 4);
	}
	{
		uint32_t array[3] = {5, 2, 3};
		testcase(solution, array, 3, 0, 0);
	}
	{
		uint32_t array[2] = {5, 2};
		testcase(solution, array, 2, 1, -1);
	}
	return 0;
}
