/*
 * including:
 *     . headers
 *     . using namespace std;
 *     . debug function
 *     . printArray
 *
 */


#ifndef COMMON_H
#define COMMON_H

#include <iostream>
using namespace std;

#define debug(x, y) std::cout << "(debug)" << x << y << std::endl;

template<class T1, class T2>
inline void idebug(T1 x, T2 y)
{
    std::cout << "(debug)" << x << ": " << y << std::endl;
}

void printArray(int* arr,int len)
{
    if (arr == NULL or len <= 0)
    {
        idebug("input error.", "");
        return ;
    }

    debug("---printArray---", "");
    
    for ( int i = 0; i < len; i++ )
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    debug("---end debug---", "");
}


#endif
