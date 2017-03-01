#include <iostream>
#include <stdint.h>


class Solution {

public:
    int myAtoi(std::string str);

private:
    bool isValid(const std::string& str);
};

int Solution::myAtoi(std::string str)
{
    if (!isValid(str))
    {
        return 0;
    }
    int result = 0;
    bool positive = true;;
    // for judge overflow
    int thresholdInt = INT32_MIN / 10;
    int thresholdRemainder = INT32_MIN % 10;
    
    for (uint32_t i = 0; i < str.length(); ++i)
    {
        if (str[i] == '-')
        {
            positive = false;
            continue;
        }
        else if (str[i] == '+')
        {
            positive = true;
            continue;
        }
        if (result < thresholdInt)
        {
            return 0;
        }
        else if (result == thresholdInt)
        {
            if ('0' - str[i] < thresholdRemainder)
            {
                return false;
            }
        }
        result = result * 10 + ('0' - str[i]);
    }
    if (result == INT32_MIN && positive)
    {
        result = 0;
    }
    else
    {
        result = positive ? 0 - result : result;
    }
    return result;
}

bool Solution::isValid(const std::string& str)
{
    if (str.length() == 0)
    {
        return false;
    }
    if (!(str[0] >= '0' && str[0] <= '9')
        && str[0] != '-'
        && str[0] != '+')
    {
        return false;
    }
    if (str.length() == 1
            && (str[0] == '-' || str[0] == '+'))
    {
        return false;
    }
    if (str.length() > 1
            && (str[0] == '-' || str[0] == '+')
            && str[1] == 0)
    {
        return false;
    }
    if (str.length() > 1
            && str[0] == '0')
    {
        return false;
    }
    for (uint32_t i = 1; i < str.length(); ++i)
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
        {
            return false;
        }
    }
    return true;
}


int main()
{
    Solution solution;
    std::cout << solution.myAtoi("") << std::endl;
    std::cout << solution.myAtoi("123") << std::endl;
    std::cout << solution.myAtoi("023") << std::endl;
    std::cout << solution.myAtoi("A23") << std::endl;
    std::cout << solution.myAtoi("0") << std::endl;
    std::cout << solution.myAtoi("2147483647") << std::endl;
    std::cout << solution.myAtoi("2147483648") << std::endl;
    std::cout << solution.myAtoi("-2147483648") << std::endl;
    std::cout << solution.myAtoi("-123") << std::endl;
    return 0;
}
