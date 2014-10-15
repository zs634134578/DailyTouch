/*
 *
 */

#include <iostream>

using namespace std;

#define debug(x, y) std::cout << "(debug)" << x << y << std::endl;
#define print(x) std::cout << x << std::endl;

class Solution
{
    public:
        int findMinDict(char* str, int len)
        {
            if (str == NULL)
                return -1;
            if ( len <= 0 )
                return -1;

            int i ,j, k;
            i = 0;
            j = 1;

            while( i<len && j<len )
            {
                debug("in while", "");
                for(k=0;k<len ;k++)
                    if (str[i+k]!= str[j+k])
                        break;
                debug("k: ", k);
                if (k > len)
                    break;
  
                if (str[(i+k)%len] > str[(j+k)%len])
                {
                    debug("k:", k);
                    i = i+k+1;
                }
                else if(str[(i+k)%len] < str[(j+k)%len])
                    j = j+k+1;
                if ( i == j ) 
                    j = i+1;
            }
            return i < j? i: j;

        }

};
int main()
{
    char str[7] = "dbfcae";
    Solution* solver = new Solution();
    int index = solver->findMinDict(str,6);
    std::cout << index << std::endl;
    print("Hello world!");
    return 0;
}
