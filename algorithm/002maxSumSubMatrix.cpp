/*
   题目：给出一个 m*n 的二维矩阵(元素可为正可为负)，求该二维矩阵的一个子矩阵，且此子矩阵中所有元素的和最大，并输出该矩阵的和。

   举例(1)

   给出4*4的二维矩阵：

   0 -2 -7  0 
   9  2 -6  2 
   -4  1 -4  1 
   -1  8  0 -2 

   和最大的子矩阵为：

   9 2 

   -4 1 

   -1 8 

   此子矩阵元素的和为15。
 */

#include <iostream>


int main()
{
    int array[4][4]={0,-2, -7, 0,
                     9, 2, -6, 2,
                     -4,1, -4, 1,
                     -1, 8, 0, -1};
    std::cout << array[3][1] << std::endl;
    std::cout << "Hello world" << std::endl;
}

