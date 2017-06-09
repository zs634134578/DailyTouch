#include<iostream>
#include <vector>
#include <limits.h>

class Solution
{
public:
    int maxSumMatrix(std::vector<std::vector<int>>& matrix)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0)
        {
            return 0;
        }
        int rowCount = matrix[0].size();
        int max = INT_MIN;
        std::vector<int> arr;
        for (int startLine = 0; startLine < matrix.size(); ++startLine)
        {
            arr.assign(rowCount, 0);
            for (int lineNum = startLine; lineNum < matrix.size(); ++lineNum)
            {
                for (int rowNum = 0; rowNum < rowCount; ++rowNum)
                {
                    arr[rowNum] += matrix[lineNum][rowNum];
                }
                int tempMax= maxSumOfArray(arr);
                max = std::max(tempMax, max);
            }
        }
        return max;
    }
private:
    int maxSumOfArray(const std::vector<int>& arr)
    {
        int max = INT_MIN;
        int cur = 0;
        for (auto each : arr)
        {
            cur = cur + each >= 0 ? cur + each : 0;
            max = cur > max ? cur : max;
        }
        return max;
    }
};


int main()
{
    std::vector<std::vector<int>> matrix = {
        {-90, 48, 78},
        {64, -40, 64},
        {-81, -7, 66}
    };
    Solution solution;
    std::cout << solution.maxSumMatrix(matrix) << std::endl;
}
