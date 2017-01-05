#include <iostream>

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

} // array
} // common
