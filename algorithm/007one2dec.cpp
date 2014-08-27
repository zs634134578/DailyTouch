#include <iostream>
#include "stdlib.h"

int main()
{
    int n;
    std::cout << "Please input n: ";
    std::cin >> n;
    char* maxNum = new char[n+1];
    maxNum[n] = '\0';
    std::cin >> maxNum;
    std::cout << maxNum << std::endl;
    delete[] maxNum;
    return 0;
    
    int i;
    for( i = 0; i < n; i++ )
        maxNum[i] = '9';
    
    int maxNumInt = atoi(maxNum);
    
    int flag = 0;
    for ( i = 1; i <= maxNumInt; i++ ){
        std::cout << i << '\t';
        flag++;
        if ( flag == 8 ) {
            std::cout << std::endl;
            flag = 0;
        }
    }

    std::cout << "Hello world" << std::endl;
    return 0;
}
