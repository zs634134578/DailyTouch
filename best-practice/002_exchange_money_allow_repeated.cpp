#include <iostream>
#include <vector>

class Solution
{
public:
	int ExchangeMoney(std::vector<uint32_t>& arr, uint32_t aim);
};

int Solution::ExchangeMoney(std::vector<uint32_t>& arr, uint32_t aim)
{
	// fix: precheck
	if (arr.size() == 0 || aim == 0)
	{
		return 0;
	}
	int arrSize = arr.size();
	int dp[arrSize][aim + 1];
	for (uint32_t lineIndex = 0; lineIndex < arrSize; ++lineIndex)
	{
		dp[lineIndex][0] = 0;
	}
	for (uint32_t rowIndex = 1; rowIndex < aim + 1; ++rowIndex)
	{
		if (int(rowIndex - arr[0]) >= 0 && dp[0][rowIndex - arr[0]] != UINT32_MAX)
		{
			dp[0][rowIndex] = dp[0][rowIndex - arr[0]] + 1;
		}
		else
		{
			dp[0][rowIndex] = UINT32_MAX;
		}
	}
	for (uint32_t lineIndex = 1; lineIndex < arrSize; ++lineIndex)
	{
		for (uint32_t rowIndex = 1; rowIndex < aim + 1; ++rowIndex)
		{
			int subCurArrValue = rowIndex - arr[lineIndex];
			uint32_t upValue = dp[lineIndex - 1][rowIndex];
			uint32_t leftValue = UINT32_MAX;
			if (subCurArrValue >= 0 && dp[lineIndex][subCurArrValue] != UINT32_MAX)
			{
				leftValue = dp[lineIndex][subCurArrValue] + 1;
			}
			dp[lineIndex][rowIndex] = leftValue < upValue ? leftValue : upValue;
		}
	}
	return dp[arrSize - 1][aim] == UINT32_MAX ? -1 : dp[arrSize - 1][aim];
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
