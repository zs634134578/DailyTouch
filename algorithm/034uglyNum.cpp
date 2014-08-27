/*
 * 问题描述：
 *     只包含因子2，3和5的数称作丑数。
 *         求按从小到大的顺序的第1500个丑数。
 *         例如：
 *             6、8是丑数，14不是丑数。
 *                 习惯上我们把1当做第一个丑数。
 */

#include <iostream>
using namespace std;

#define debug(x, y) std::cout << "(debug)"<< x << y << std::endl;
#define print(x)    std::cout << x << std::endl;

class Solution
{
public:
    int getUglyNum(int seqNum)
    {
        if (seqNum <= 0)
           return 0;
        int * unums = new int[seqNum];
        unums[0] = 1;
        int next = 1;
        int* pMulti2 = unums;
        int* pMulti3 = unums;
        int* pMulti5 = unums;

        while(next < seqNum)
        {
            int min = Min(*pMulti2*2, *pMulti3*3, *pMulti5*5);
            unums[next] = min;
            while(*pMulti2 * 2 <= unums[next])
                ++pMulti2;
            while(*pMulti3 * 3 <= unums[next])
                ++pMulti3;
            while(*pMulti5 * 5 <= unums[next])
                ++pMulti5;
            ++next;
        }
        int ugly = unums[next-1];
        delete[] unums;
        return ugly;
       } 
    int Min(int number1, int number2, int number3)
    {
        int min = (number1 < number2) ? number1 : number2;
        return (min < number3)? min : number3;
    }
};

int main()
{
    Solution* solver = new Solution();
    int result = solver->getUglyNum(1500);
    print(result);
    print("Hello world!");
    return 0;
}
