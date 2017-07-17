#include <iostream>
#include <vector>
#include "../common/array.h"

class Solution
{
public:
    void sort(std::vector<int>& A)
    {
        mergeSort(A, 0, A.size() - 1);
    }
private:
    void mergeSort(std::vector<int>& nums, int start, int end)
    {
        if (start < end)
        {
            int mid = (start + end) / 2;
            mergeSort(nums, start, mid);
            mergeSort(nums, mid + 1, end);
            merge(nums, start, mid, end);
        }
    }
    void merge(std::vector<int>& nums, int start, int mid, int end)
    {
        std::vector<int> tmpVec;
        int left = start;
        int right = mid + 1;
        while (left <= mid && right <= end)
        {
            if (nums[left] <= nums[right])
            {
                tmpVec.push_back(nums[left]);
                ++left;
            }
            else
            {
                tmpVec.push_back(nums[right]);
                ++right;
            }
        }
        while (left <= mid)
        {
            tmpVec.push_back(nums[left++]);
        }
        while (right <= end)
        {
            tmpVec.push_back(nums[right++]);
        }
        for (int i = 0; i < tmpVec.size(); ++i)
        {
            nums[start + i] = tmpVec[i];
        }
    }
};


int main()
{
    Solution solution;
    std::vector<int> A = {6,2,4,1,7,3,8,5,9};
    solution.sort(A);
    common::array::print(A);
    return 0;
}
