#include <iostream>
#include <vector>

class Solution {

public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        std::vector<int> result;
        size_t lineNum = matrix.size();
        if (lineNum == 0)
        {
            return result;
        }
        size_t rowNum = matrix[0].size();
        if (rowNum == 0)
        {
            return result;
        }
        int ll = 0;
        int lr = 0;
        int rl = lineNum - 1;
        int rr = rowNum - 1;
        for (; ll <= rl && lr <= rr; ++ll, ++lr, --rl, --rr)
        {
            printEachRound(matrix, ll, lr, rl, rr, result);
        }
        return result;
    }
private:
    void printEachRound(const std::vector<std::vector<int>>& matrix,
                        int ll, int lr,
                        int rl, int rr,
                        std::vector<int>& result)
    {
        for (int row = lr; row <= rr; ++row)
        {
            result.push_back(matrix[ll][row]);
        }
        for (int line = ll + 1; line <= rl; ++line)
        {
            result.push_back(matrix[line][rr]);
        }
        for (int row = rr - 1; row >= lr; --row)
        {
            result.push_back(matrix[rl][row]);
        }
        for (int line = rl - 1; line >= ll + 1; --line)
        {
            result.push_back(matrix[line][lr]);
        }
    }
};

int main()
{
    std::vector<std::vector<int>> matrix = {{1,   2,  3,  4},
                                             {5,   6,  7,  8},
                                             {9,  10, 11, 12},
                                             {13, 14, 15, 16}};
    Solution solution;
    solution.spiralOrder(matrix);
    std::vector<std::vector<int>> matrix2 = {{1,   2,  3},
                                             {5,   6,  7},
                                             {9,  10, 11},
                                             {13, 14, 15}};
    solution.spiralOrder(matrix2);
    return 0;
}
