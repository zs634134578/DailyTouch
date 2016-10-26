#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define println(x) std::cout << x << std::endl;
#define print(x) std::cout << x << " ";

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::map<int, int> hashMap;
        std::vector<int> results;
        for (std::vector<int>::iterator it = nums.begin();
             it != nums.end();
             ++it)
        {
            if (hashMap.find(target - *it) != hashMap.end())
            {
                results.push_back(hashMap[target - *it]);
                results.push_back(it - nums.begin());
            }
            else
            {
                hashMap.insert(std::make_pair(*it, it - nums.begin()));
            }
        }
        return results;
    }
};

int main()
{
    int target = 6;
    std::vector<int> testcase;
    testcase.push_back(3);
    testcase.push_back(2);
    testcase.push_back(4);
    Solution solution;
    std::vector<int> results = solution.twoSum(testcase, target);
    print(results[0]);
    println(results[1]);
    return 0;
}
