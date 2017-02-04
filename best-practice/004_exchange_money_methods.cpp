/*
 * 暴力递归
 */

#include <iostream>
#include <vector>

class Solution
{
public:
	int ExchangeMoney(std::vector<uint32_t>& arr, uint32_t aim);
private:
	int process(std::vector<uint32_t>& arr, uint32_t index, uint32_t aim);
};

int Solution::ExchangeMoney(std::vector<uint32_t>& arr, uint32_t aim)
{
	if (aim == 0)
	{
		return 1;
	}
	if (arr.size() == 0)
	{
		return 0;
	}
	return process(arr, 0, aim);
}

int Solution::process(std::vector<uint32_t>& arr, uint32_t index, uint32_t aim)
{
	int ret = 0;
	if (index == arr.size())
	{
		ret = 0 == aim ? 1 : 0;
	}
	else
	{
		for (uint32_t k = 0; k * arr[index] <= aim; ++k)
		{
			ret += process(arr, index + 1, aim - k * arr[index]);
		}
	}
	return ret;
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
		uint32_t array[4] = {5, 10, 25, 1};
		testcase(solution, array, 4, 0, 1);
	}
	{
		uint32_t array[4] = {5, 10, 25, 1};
		testcase(solution, array, 4, 15, 6);
	}
	{
		uint32_t array[2] = {3, 5};
		testcase(solution, array, 2, 2, 0);
	}
	return 0;
}
