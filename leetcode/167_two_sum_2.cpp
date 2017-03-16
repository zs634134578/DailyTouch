#include <iostream>
#include <vector>
#include <map>

class Solution
{
    std::vector<int> twoSum(std::vector<int>& numbers, int target) 
    {
        std::map<int, int> hashMap;
        std::vector<int> result;
        for (std::vector<int>::const_iterator it = numbers.begin();
             it != numbers.end();
             ++it)
        {
            std::map<int, int>::iterator tempIt = hashMap.find(target - *it);
            if (tempIt != hashMap.end())
            {
                int firstIndex = it - numbers.begin() < tempIt->second ? it - numbers.begin() : tempIt->second;
                int secondIndex = it - numbers.begin() < tempIt->second ? tempIt->second : it - numbers.begin();
                result.push_back(firstIndex + 1);
                result.push_back(secondIndex + 1);
                break;
            }
            else
            {
                hashMap.insert(std::make_pair(*it, it - numbers.begin()));
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}
