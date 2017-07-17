#include <iostream>
#include <vector>
#include "../common/array.h"

class Solution
{
public:
    void sort(std::vector<int>& A)
    {
        if (A.size() == 0)
        {
            return;
        }
        quicksort(A, 0, A.size() - 1);
    }

private:
    void quicksort(std::vector<int>& nums, int start, int end)
    {
        if (start >= end) return;

        int mid = partition(nums, start, end);
        if (mid - 1 > start)
        {
            quicksort(nums, start, mid - 1);
        }
        if (mid + 1 < end)
        {
            quicksort(nums, mid + 1, end);
        }
    }
    int partition(std::vector<int>& nums, int start, int end)
    {
        int pivot = nums[start];
        int left = start;
        for (int i = start + 1; i <= end; ++i)
        {
            if (nums[i] < pivot)
            {
                left++;
                swap(nums, left, i);
            }
        }
        swap(nums, left, start);
        return left;
    }
    int swap(std::vector<int>& nums, int i, int j)
    {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
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
