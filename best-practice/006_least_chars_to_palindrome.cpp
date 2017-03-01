#include <iostream>

class Solution
{
public:
    std::string transfer2Palindrome(std::string srcStr)
    {
        if (srcStr.size() == 0)
        {
            return srcStr;
        }
        std::string targetStr;

        int size = srcStr.size();
        int dp[size][size];
        genDp(srcStr, (int *)dp, size);
        /*
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                std::cout << *(*(dp + i) + j) << " ";
            }
            std::cout << std::endl;
        }
        */
        return transferByDp(srcStr, (int *)dp, size);
    }

    std::string transferByDp(const std::string& srcStr, int* dp, int size)
    {
        std::string result;
        int resultLen = srcStr.size() + *(dp + 0 * size + size - 1);
        result.resize(resultLen);
        int left = 0;
        int right = resultLen - 1;
        int srcLeft = 0;
        int srcRight = srcStr.size() - 1;
        while (left <= right)
        {
            if (*(dp + left * size + right) == *(dp + (left + 1) * size + right - 1))
            {
                result[left++] = srcStr[srcLeft++];
                result[right--] = srcStr[srcRight--];
            }
            else if (*(dp + left * size + right) == *(dp + (left + 1) * size + right) + 1)
            {
                result[left++] = srcStr[srcLeft];
                result[right--] = srcStr[srcLeft++];
            }
            else
            {
                result[left++] = srcStr[srcRight];
                result[right--] = srcStr[srcRight--];
            }
        }
        return result;
    }

    void genDp(const std::string& srcStr, int* dp, int size)
    {
        for (int i = 0; i < size; ++i)
        {
            *(dp + i * size + i) = 0;
        }
        for (int row = 1; row < size; ++row)
        {
            *(dp + (row - 1) * size + row) = srcStr[row-1] == srcStr[row] ? 0 : 1;
            for (int line = row - 2; line > -1; --line)
            {
                if (srcStr[line] == srcStr[row])
                {
                    *(dp + line * size + row) = *(dp + (line + 1) * size + row - 1);
                }
                else
                {
                    int rightAddDpValue = *(dp + (line + 1) * size + row) + 1;
                    int leftAddDpValue = *(dp + line * size + row - 1) + 1;
                    *(dp + line * size + row) = rightAddDpValue < leftAddDpValue ? rightAddDpValue : leftAddDpValue;
                }
            }
        }
    }
};

int main()
{
    Solution solution;
    std::cout << solution.transfer2Palindrome("A1B21C") << std::endl;
    return 0;
}
