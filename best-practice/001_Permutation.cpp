#include <iostream>
#include <string.h>
#include <vector>

#define DEBUG(info) \

//	std::cout << "DEBUG:" << info << std::endl;

class PermAndCombTool
{
public:
	explicit PermAndCombTool()
	{}

	void SetAndRun(char* str, int mode);

	/*
	 * 全排列递归实现，不考虑重复字符情况
	 * 算法：从前往后，每个字符和其后的字符交换一次，即得到所有字符串
	 */
	void DoPermAndCombToolWithoutRepeatRecursively(char* str, char* begin);
	/*
	 * 全排列递归实现，考虑重复字符情况
	 * 算法：从前往后，每个字符和其后的字符交换一次，如果字符相同，则不交换
	 *       即得到所有字符串
	 */
	void DoPermAndCombToolWithRepeatRecursively(char* str, char* begin);

	/*
	 * 全组合递归实现
	 */
	void DoCombinationRecursively(char* str);
	void doCombination(char* str, int start, int count, std::vector<char>& result);

	void swap(char* a, char* b);
	bool isSwap(char* a, char* b);
	void printVec(const std::vector<char>& result);
};

void PermAndCombTool::DoCombinationRecursively(char* str)
{
	int count = strlen(str);
	std::vector<char> result;
	for (int subCount = 1; subCount <= count; ++subCount)
	{
		doCombination(str, 0, subCount, result);
	}
}

void PermAndCombTool::printVec(const std::vector<char>& result)
{
	for (std::vector<char>::const_iterator it = result.begin();
			it != result.end();
			++it)
	{
		std::cout << *it;
	}
	std::cout << " ";
}

void PermAndCombTool::doCombination(char* str, int start, int count, std::vector<char>& result)
{
	if (count == 0)
	{
		printVec(result);
		return;
	}
	if (*str == '\0')
	{
		return;
	}
	result.push_back(*str);
	doCombination(str + 1, start + 1, count - 1, result);
	result.pop_back();
	doCombination(str + 1, start + 1, count, result);
}

void PermAndCombTool::SetAndRun(char* str, int mode)
{
	std::cout << "Origin: " << str << std::endl;
	std::cout << "Mode: " << mode << std::endl;
	std::cout << "Result: ";
	switch (mode)
	{
		case 1:
			DoPermAndCombToolWithoutRepeatRecursively(str, str);
			break;
		case 2:
			DoPermAndCombToolWithRepeatRecursively(str, str);
			break;
		case 3:
			DoCombinationRecursively(str);
			break;
		default:
			DEBUG("Run mode is needed");
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

void PermAndCombTool::swap(char* a, char* b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}

bool PermAndCombTool::isSwap(char* begin, char* end)
{
	for (char* p = begin; p < end; ++p)
	{
		if (*p == *end)
		{
			return false;
		}
	}
	return true;
}

void PermAndCombTool::DoPermAndCombToolWithRepeatRecursively(char* str, char* begin)
{
	DEBUG(__func__);
	DEBUG(str);
	DEBUG(begin - str);
	if (str == NULL || begin == NULL)
	{
		DEBUG("Invalid parameter");
		return;
	}
	if (*begin == '\0')
	{
		std::cout << str << " ";
		return;
	}
	for (char* p = begin; *p != '\0'; ++p)
	{
		if (isSwap(begin, p))
		{
			swap(begin, p);
			DoPermAndCombToolWithRepeatRecursively(str, begin+1);
			swap(p, begin);
		}
	}
}


void PermAndCombTool::DoPermAndCombToolWithoutRepeatRecursively(char* str, char* begin)
{
	// DEBUG(__func__);
	if (str == NULL || begin == NULL)
	{
		DEBUG("Invalid parameter");
		return;
	}
	if (*begin == '\0')
	{
		std::cout << str << " ";
		return;
	}
	for (char* p = begin; *p != '\0'; ++p)
	{
		swap(begin, p);
		DoPermAndCombToolWithoutRepeatRecursively(str, begin+1);
		swap(p, begin);
	}
}

int main()
{
	PermAndCombTool tool;

	std::cout << "===== Permutation Tests =====" << std::endl;
	char str1[] = "abc";
	tool.SetAndRun(str1, 1);
	char str2[] = "abcd";
	tool.SetAndRun(str2, 1);
	char str3[] = "aaa";
	tool.SetAndRun(str3, 1);
	tool.SetAndRun(str3, 2);
	char str4[] = "abb";
	tool.SetAndRun(str4, 2);
	char str5[] = "abbc";
	tool.SetAndRun(str5, 2);

	std::cout << std::endl;
	std::cout << "===== Combination Tests =====" << std::endl;
	tool.SetAndRun(str1, 3);
	tool.SetAndRun(str3, 3);
    return 0;
}
