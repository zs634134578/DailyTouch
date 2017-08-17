#include "../array.h"

int main()
{
    common::array::print("test1", 1);
    common::array::print("test2", 2.0);
    common::array::print("test3", "print string");
    std::vector<int> nums = {123, 456, 789};
    std::string str("test4");
    common::array::print(&str, &nums);
    return 0;
}
