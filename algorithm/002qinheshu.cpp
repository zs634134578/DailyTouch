/*
 * 每日一题(2) 亲和数问题-求解500万以内的亲和数 
 */
#include<iostream>

#define eleNum 500001

int main()
{
    int array[eleNum] = {0};
    int i, j;

    for ( i = 1; i < eleNum; i++ )
        array[i] = 1;

    for ( i = 2; i + i < eleNum; i++ )
    {
        j = i * 2;
        while ( j < eleNum ) {
            array[j] += i;
            j+=i;
        }
    }

    for ( i = 1; i < eleNum; i++ )
    {
        if( array[i] > i && array[i] < eleNum && array[array[i]] == i )
            std::cout << i << "\t" << array[i] << std::endl;
    }
    

    std::cout << "Hello world!" << std::endl;
}
