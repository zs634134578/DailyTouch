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
#include <vector>
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

template<class T>
void printVec(vector<T> tvec)
{
    typename::vector<T>::iterator it;
    for( it = tvec.begin(); it != tvec.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template<class T>
void printList(T* head)
{
    if ( head == NULL)
    {
        std::cout << "list is NULL" << std::endl;
        return;
    }
    while(head != NULL)
    {
        std::cout << head->label << " ";
        head = head->next;
    }
    std::cout << std::endl;
}


#endif
