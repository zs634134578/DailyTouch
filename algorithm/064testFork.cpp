/*
 *
 */

#include <iostream>
#include <stdio.h>
//#include <sys/types.h>
#include <unistd.h>

using namespace std;

#define debug(x, y) std::cout << "(debug)" << x << y << std::endl;
#define print(x) std::cout << x << std::endl;

class Solution
{

};
int main()
{
    Solution* solver = new Solution();
    
    for( int i = 0; i < 2; i++)
    {
        fork();
        printf("ppid:%d, pid:%d, i=%d\n", getppid(),getpid(), i);
    }
    printf("\n");
    return 0;
}
