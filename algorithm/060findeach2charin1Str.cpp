/*
 * 问题描述：
 *    输入两个字符串，比如abdbcc和abc，输出第二个字符串在第一个字符串中的连接次序。
 *       即输出125, 146, 145, 146。
 */

#include <iostream>
#include <string.h>

using namespace std;

#define debug(x, y) std::cout << "(debug)" << x << y << std::endl;
#define print(x) std::cout << x << std::endl;

class Solution
{
public:
    void findEach(char* str1, char* str2, int index, int* records)
    /*
     * records用来记录各个str2的元素在str1中的位置，当扫描完毕，一次打印出该数组
     */
    {
        if ( str2[index] == '\0' ) {
            for( int i = 0; i < 3; i++ )
            {
                std::cout << records[i] ;
            }
            std::cout << std::endl;
            return;
        }

        int len = strlen(str1);
        for ( int i = 0; i < len; i++  )
        {
            if ( str1[i] == str2[index] )
            {
                records[index] = i + 1;
                findEach(str1, str2, index+1, records);
            }
        }

    }

};
int main()
{
    char str1[7] = "abdbcc"; char str2[4] = "abc";
    Solution* solver = new Solution();
    int records[3] = {0};
    solver->findEach(str1, str2, 0, records);
    print("Hello world!");
    return 0;
}
