#include <iostream>

double Power( double base, int exponent );
double powerAbs( double base, unsigned int exponent );
int main()
{
    double base;
    int exponent;
    while(1) {
        std::cout << "base: ";
        std::cin >> base;
        std::cout << "exponent: ";
        std::cin >> exponent;
        std::cout << "result: " << Power(base, exponent) << std::endl; 
    }
    std::cout << "Hello world" << std::endl << std::endl;
    return 0;
}

double Power( double base, int exponent)
{
    int flag = 0;
    if ( exponent < 0 )
    {
        exponent = -exponent;
        flag = 1;
    }
    double result = powerAbs(base, exponent);
    return flag ? 1/result:result;
}


double powerAbs( double base, unsigned int exponent )
{
    if ( exponent == 0 || base == 0 )
        return 1;
    if ( exponent == 1 )
        return base;

    double result = powerAbs(base, exponent >> 1);
    result *= result;

    if ( exponent & 0x01 == 1 )
        result *= base;

    return result;
}
