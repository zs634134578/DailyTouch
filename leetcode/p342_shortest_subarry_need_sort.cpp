#include <iostream>
#include <vector>

class Solution
{
public:
    int shortest(const std::vector<int>& arr)
    {
        int size = arr.size();
        if (size <= 1)
        {
            return 0;
        }
        int left = -1;
        int right = -1;
        // scan from right to left
        int min = arr[size - 1];
        for (int i = size - 2; i >= 0; --i)
        {
            min < arr[i] ? left = i : min = arr[i];
        }
        if (left == -1) return 0;
        int max = arr[0];
        for (int i = 1; i < size; ++i)
        {
            max > arr[i] ? right = i : max = arr[i];
        }
        return right - left + 1;
    }
};

int main()
{
    std::vector<int> arr= {1, 5, 3, 4, 2, 6, 7};
    Solution solution;
    std::cout << solution.shortest(arr) << std::endl;
    return 0;
}
