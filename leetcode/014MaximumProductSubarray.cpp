/*
 *
 */

#include "common.h"

using namespace std;

#define print(x) std::cout << x << std::endl;

class Solution
{
public:

    long max3(long a, long b, long c)
    {
        debug("a:", a);
        debug("b:", b);
        debug("c:", c);

        long d = a > b ? a : b;
        debug("d:", c);
        return d > c ? d : c;
    }

    long min3(long a, long b, long c)
    {
        long d = a < b ? a : b;
        return d < c ? d : c;
    }


    int maxProduct3(int arr[], int n)
    {
        if ( n == 1)
            return arr[0];
        long max = arr[0];
        long min = arr[0]; 
        long result = arr[0];
        long tmpMax;
        long tmpMin;
        for(int i = 1; i < n; i++)
        {
            debug("old max:", max);
            debug("old min:", min);

            tmpMax = max * arr[i];
            tmpMin = min * arr[i];
            debug("tmpMax:", tmpMax);
            debug("tmpMin:", tmpMin);
            max = max3(tmpMax, tmpMin, arr[i]);
            min = min3(tmpMax, tmpMin, arr[i]);
            result = result > max ? result : max ;
            debug("max:", max);
            debug("min:", min);
            debug("result:", result);
        }
        return result;
    }

    
    int maxProduct1(int arr[], int n) {
        /*
         * 暴力法
         */
        long max = 0;
        long mulResult = 0;
        for ( int i = 0; i < n; i++ )                
        {
            mulResult = arr[i];
            for( int j = i + 1; j < n; j++)
            {
                mulResult *= arr[j];
                if ( mulResult > max ) 
                    max = mulResult;
            }
        }
        return max;
    }
    
    /* 方法二
     * 通过判断负数的个数，0的个数来进行分类讨论，暂不考虑小数
     */


    int NumberOfNeg(int arr[], int left, int right)
    {
        int number = 0;
        for( int i=left; i <= right; i++)
        {
            if ( arr[i] < 0 )
                number++;
        }
        return number;
    }

    int getFirstNeg(int arr[], int left, int right)
    {
        for(int i = left; i <= right; i++)
            if (arr[i] < 0)
                return i;
        return -1;
    }
    
    int getLastNeg(int arr[], int left, int right)
    {
        for(int i = right; i >= left; i++)
            if (arr[i] < 0 )
                return i;
        return -1;
    }

    int* hasZero(int arr[], int left, int right)
    {
        int * zeroIndexs = new int[right - left + 1];
        for(int i = 0; i <= right; i++)
            zeroIndexs[i] = -1; 
        for ( int i = left, j = 0; i <= right; i++)
            if ( arr[i] == 0)
            {
                zeroIndexs[j++] = i;
            }
        return zeroIndexs;
    }

    long multiPart(int arr[], int left, int right)
    {
        if ( left > right)
            return 0;
        long result = 1;
        for( int i = left; i <= right; i++)
            result *= arr[i];
        return result;
    }
    int maxProduct(int arr[], int n)
    {
        return maxProduct2(arr, 0, n-1);
    }

    int maxProduct2(int arr[], int left, int right)
    /*
     * 分类讨论
     * 1 当无0，负数个数为偶数时，直接相乘
     * 2 当无0，负数个数为奇数时，比较最右边的负数之前所有数的积（不包含本身），和最左边的负数之后所有数的积（不包含本身）
     * 3 当有0时，比较0左右两个子数组的积
    */ 
    {
        if ( left > right)
            return 0;
        int* zeroIndexs = this->hasZero(arr, left, right);
        long result;
        if ( zeroIndexs[0] == -1)
        {
            // 无0，通过判断负数个数进行计算
            int numOfNeg = this->NumberOfNeg(arr, left, right);
            if ( numOfNeg % 2 == 0)
                result = this->multiPart(arr, left, right);
            else
            {
                int first = this->getFirstNeg(arr, left, right);
                int last = this->getLastNeg(arr, left, right);
                long result1= this->multiPart(arr, first + 1, right);
                long result2= this->multiPart(arr, left, last -1 );
                result = result1 > result? result1: result2;
            }
        }
        else
        {
            for ( int i = 0; i < right - left + 1; i++)
            {
                if ( zeroIndexs[i] != -1)
                {
                    int start;
                    if ( i == 0)
                        start = 0;
                    else
                        start = zeroIndexs[i-1] + 1;
                    int end = zeroIndexs[i] - 1;
                    long tmp = this->maxProduct2(arr, start, end);
                    result = result > tmp? result : tmp;
                }
                else 
                {
                    long tmp = this->maxProduct2(arr, zeroIndexs[i-1]+1, right);
                    result = result > tmp ? result : tmp;
                    break;
                }
            }
        }
        return result;
        
    }
    
};

int main()
{
    Solution* solver = new Solution();
    int arr[3] = {-2, -3, 7};
    long result1 = solver->maxProduct1(arr, 3);
    long result2 = solver->maxProduct(arr, 3);
    long result3 =solver->maxProduct3(arr, 3);
    debug("result1: ", result1);
    debug("result2: ", result2);
    debug("result3: ", result3);

    print("Hello world!");
    return 0;
}
