/*
 *    在数组中的两个数字如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
 *    输入一个数组，求出这个数组中的逆序对的总数。
 *    方法：在归并排序的过程中统计逆序对。
 */

#include <iostream>
#include <cstdlib>

using namespace std;

#define debug(x, y) std::cout << "(debug)" << x << y << std::endl;
#define print(x) std::cout << x << std::endl;

void printArray(int* array, int len);
class Solution
{
public:
    int countReverse(int* intArray, int len)
    {
        if (intArray == NULL || len <= 1)
            return 0;

        int *copyArray = new int[len];
        for( int i = 0; i < len ; i++)
            copyArray[i] = intArray[i];

        debug("init copyArray:", "");
        printArray(copyArray, len);

        int count = mergeAndCount(intArray, copyArray, 0, len-1);
        delete[] copyArray;
        return count;
    }
    
    int mergeAndCount(int* intArray,int* copy,  int start, int end)
    {
        std::cout << std::endl;
        debug("copy: ","");
        printArray(intArray, 5);
        printArray(copy, 5);
        debug("start: ", start);
        debug("end: ", end);
        //exit(0);

        if (start == end)
        {
            copy[start] = intArray[start];
            return 0;
        }
        int len = (end - start) / 2;

        int count1 = mergeAndCount( copy, intArray, start, start + len);
        int count2 = mergeAndCount(copy, intArray,start + len +1, end);

        int count3 = 0;
        int leftStart = start;
        int leftEnd = start + len;
        int rightStart = leftEnd + 1;
        int rightEnd = end;
        int indexCopy = end;

        while( leftEnd >= leftStart && rightEnd >= rightStart)
        {
            if (intArray[leftEnd]> intArray[rightEnd])
            {
                printArray(intArray, end-start+1);
                debug("leftEnd:", leftEnd);
                debug("rightEnd:", rightEnd);
                count3 += rightEnd - rightStart + 1;
                copy[indexCopy--] = intArray[leftEnd--];
                debug("count3:", count3);
            }
            else if ( intArray[leftEnd]< intArray[rightEnd])
            {
                copy[indexCopy--] = intArray[rightEnd--];
            }
            else
            {
                copy[indexCopy--] = intArray[rightEnd--];
                copy[indexCopy--] = intArray[leftEnd--];
            }
        }
        while(leftEnd > leftStart)
            copy[indexCopy--] = intArray[leftEnd--];
        while(rightEnd > rightStart)
            copy[indexCopy--] = intArray[rightEnd--];

        print("\n");
        debug("count1:", count1);
        debug("count2:", count2);
        debug("count3:", count3);
        debug("===", "\n")
        return count1 + count2 + count3;
    }

};

void printArray(int* array, int len)
{
    for(int i = 0; i < len; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    Solution* solver = new Solution();
    int array[5] = {7,5,6,4,1}; 
    int result = solver->countReverse(array, 5);
    print(result);
    print("Hello world!");
    return 0;
}



