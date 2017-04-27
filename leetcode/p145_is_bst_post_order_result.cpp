#include <iostream>
#include <vector>

#include "../common/tree/binary_tree.h"

using namespace common::tree;

class Solution
{
public:
    bool isPostOrderResult(const std::vector<int>& arr, int start, int end)
    {
        if (start >= end)
        {
            return true;
        }
        int mid = 0;
        for (int i = start; i <= end; ++i)
        {
            mid = i;
            if (arr[i] > arr[end])
            {
                break;
            }
        }
        for (int i = mid; i < end; ++i)
        {
            if (arr[i] < arr[end])
            {
                std::cout << i << " : " << arr[i] << " " << end << " : " << arr[end] << std::endl;
                return false;
            }
        }
        return isPostOrderResult(arr, start, mid - 1) && isPostOrderResult(arr, mid, end - 1);
    }
};

int main()
{
    std::vector<int> arr{1, 4, 3, 2, 6, 8, 9, 7, 5};
    Solution solution;
    std::cout << solution.isPostOrderResult(arr, 0, arr.size() - 1) << std::endl;

    std::vector<int> arr1{1, 4, 8, 2, 6, 3, 9, 7, 5};
    std::cout << solution.isPostOrderResult(arr1, 0, arr.size() - 1) << std::endl;
    return 0;
}
