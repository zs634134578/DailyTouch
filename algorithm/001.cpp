#include <iostream>

#define debug(x,y) std::cout << "debug: " << x << " = "<< y << std::endl;

void maxSubSum(int* array, int len, int* maxSubSum);

int main() {
    int array[8] = {-1, -2, -3, -10, -4, -7, -2, -5};
    int len = 8;
    int maxSum = 0;

    maxSubSum(array, len, &maxSum);
    std::cout << "maxSubSum: " << maxSum << std::endl;
}


void maxSubSum(int* array, int len, int* maxSum)
{
    int tmpSum = 0;
    int i = 0;

    for( ; i < len; i++ )
    {
        tmpSum += array[i];
        if ( tmpSum < 0 )
            tmpSum = 0;
        else if ( tmpSum > *maxSum )
            *maxSum = tmpSum;
        debug("tmpSum", tmpSum);
        debug("maxSum", *maxSum);
    }

}


