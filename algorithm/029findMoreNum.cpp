/*
 * 问题描述：
 *     数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
 *     例如：
 *         输入：{ 1,2,3,2,2,2,5,4,2 }
 *             输出：5
 */

#include <iostream>
#include <cstdlib> 
using namespace std;

#define debug(x, y)  std::cout << "(debug) " << x << " " << y << std::endl;

class Solution
{
public:
    int find(int array[], int start, int end){
        debug("start:", start);
        debug("end: ", end);
        if (start > end)
            return -1;
        if (array == NULL) 
            return -1;
        if (end - start <= 2)
            return array[0];
        int index = partition(array, start, end); 
        int mid = (start + end) / 2;
        while(index != mid) 
        {
            if (index > mid)
                index = partition(array, start, index-1);
            if (index < mid)
                index = partition(array, index + 1, start);
        }
        int result = array[mid];
        return result;
    }

    int partition(int array[], int start, int end)
    {
        int i=start-1, j=start;
        int datum = array[end]; 
        int tmp;
        while(j < end){
            if (array[j] <= datum) 
            {
                tmp = array[j];
                array[j] = array[++i];
                array[i] = tmp;
                j++;
            }
            else{
               ++j; 
            }
        }
        int mid = ++i;
        tmp = array[end];
        array[end] = array[mid];
        array[mid] = tmp;

        return mid;
    }

    void printArray(int array[], int len)
    {
        for(int i = 0; i < len; i++)
        {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }
};


void test1()
{
    Solution *solver = new Solution();
    int array[9] = {1,2,3,2,2,2,5,4,2};
    int debugmid = solver->partition(array, 0, 8);
    debug("debugmid:", debugmid);
}

void test2()
{
    Solution *solver = new Solution();
    int array[9] = {1,2,3,2,2,2,5,4,2};
    int result = solver->find(array, 0, 8);
    std::cout << "result: " << result << std::endl;
    return;
}

int main()
{
    //test1();
    test2();
    debug("Start:", "Hello world!");
    return 0;
}
