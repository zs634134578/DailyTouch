#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
    struct Point;
public:
    std::vector<int> printZMatrix(std::vector<std::vector<int> > &matrix)
    {
        std::vector<int> result;
        int lineNum = matrix.size();
        if (lineNum == 0)
        {
            return result;
        }
        int rowNum = matrix[0].size();
        if (rowNum == 0)
        {
            return result;
        }
        bool fromUp = false;
        int upx = 0;
        int upy = 0;
        int downx = 0;
        int downy = 0;
        while (upx < lineNum)
        {
            printEachLine(matrix, upx, upy, downx, downy, fromUp, result);
            upy < rowNum - 1 ? ++upy : ++upx;
            downx < lineNum - 1 ? ++downx : ++downy;
            fromUp = !fromUp;
        }
    }
private:
    void printEachLine(std::vector<std::vector<int> >& matrix,
                       int upx, int upy,
                       int downx, int downy,
                       bool fromUp, std::vector<int>& result)
    {
        if (fromUp)
        {
            while (upx <= downx)
            {
                result.push_back(matrix[upx++][upy--]);
            }
        }
        else
        {
            while (downy <= upy)
            {
                result.push_back(matrix[downx--][downy++]);
            }
        }
    }
};

int main()
{
    Solution solution;
    std::vector<std::vector<int>> matrix = {{1,   2,  3,  4},
                                            {5,   6,  7,  8},
                                            {9,  10, 11, 12}};
    std::vector<int> result = solution.printZMatrix(matrix);
    std::for_each(result.begin(), result.end(), [](int val){
                std::cout << val << " ";
            });
    std::cout << std::endl;
    return 0;
}
