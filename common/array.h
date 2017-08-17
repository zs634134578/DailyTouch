#include <iostream>
#include <vector>

namespace common
{
namespace array
{

template <class T1, class T2>
void print(T1 info, T2 ele)
{
    std::cout << info << ": " << ele << std::endl;
}

template < >
void print<std::string*, std::vector<int>*>(std::string* info, std::vector<int>* ivec)
{
    std::cout << *info << std::endl;
    std::cout << "\t"; 
    for (auto i : *ivec)
    {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
}

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
