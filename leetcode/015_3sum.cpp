#include <iostream>
#include <vector>
#include <algorithm>

class Solution {

public:
    std::vector<std::vector<int> > threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int> > results;
        std::sort(nums.begin(), nums.end());
        for (std::vector<int>::iterator it = nums.begin();
             it != nums.end();)
        {
            std::cout << "first:" << *it << std::endl;
            int target = 0 - *it;
            std::vector<int>::iterator head = it + 1;
            std::vector<int>::iterator tail = nums.end() - 1;
            while (head < tail)
            {
                std::vector<int> result;
                if (*head + *tail == target)
                {
                    result.push_back(*it);
                    result.push_back(*head);
                    result.push_back(*tail);
                    results.push_back(result);
                    ++head;
                    --tail;
                }
                else if (*head + *tail < target)
                {
                    ++head;
                    continue;
                }
                else
                {
                    --tail;
                    continue;
                }
                while (head < tail && *head == result[1]) ++head;
                while (tail > head && *tail == result[2]) --tail;
            }
            int curValue = *it;
            ++it;
            while (it < nums.end() && *it == curValue) ++it;
        }
        return results;
    }

};

int main()
{
    Solution solution;
    int arr[6] = {-1, 0, 1, 2, -1, -4};
    std::vector<int> nums(arr, arr + 6);
    std::vector<std::vector<int> > results = solution.threeSum(nums);
    for (std::vector<std::vector<int> >::iterator i = results.begin();
         i != results.end();
         ++i)
    {
        for (std::vector<int>::iterator j = i->begin();
             j != i->end();
             ++j)
        {
            std::cout << *j << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
