#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    void rotate(std::vector<std::vector<int> > &matrix) {
        int lineNum = matrix.size();
        if (lineNum == 0) return;
        int rowNum = matrix.size();
        if (rowNum == 0)  return;
        int temp = 0;
        for (int lineTop = 0, lineBottom = lineNum - 1; lineTop < lineBottom; ++lineTop, --lineBottom)
        {
            for (int row = 0; row < rowNum; ++row)
            {
                temp = matrix[lineTop][row];
                matrix[lineTop][row] = matrix[lineBottom][row];
                matrix[lineBottom][row] = temp;
            }
        }
        for (int line = 0; line < lineNum; ++line)
        {
            for (int row = line + 1; row < rowNum; ++row)
            {
                temp = matrix[line][row];
                matrix[line][row] = matrix[row][line];
                matrix[row][line]= temp;
            }
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
    std::for_each(matrix.begin(), matrix.end(), [](std::vector<int>& eachLine) {
                std::for_each(eachLine.begin(), eachLine.end(), [](int val) {
                    std::cout << val << " ";
                });
                std::cout << std::endl;
            });
    solution.rotate(matrix);
    std::cout << std::endl;
    std::for_each(matrix.begin(), matrix.end(), [](std::vector<int>& eachLine) {
                std::for_each(eachLine.begin(), eachLine.end(), [](int val) {
                    std::cout << val << " ";
                });
                std::cout << std::endl;
            });
    return 0;
}
