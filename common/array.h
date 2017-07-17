#include <iostream>
#include <vector>

namespace common
{
namespace array
{

void print(int* array, int len)
{
    for (int index = 0; index < len; ++index)
    {
        if (index != len - 1)
        {
            std::cout << array[index] << ", ";
        }
        else
        {
            std::cout << array[index] << std::endl;
        }
    }
}

void print(const std::vector<int>& nums)
{
    for (auto num : nums)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

} // array
} // common
