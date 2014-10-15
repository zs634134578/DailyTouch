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
    Solution(char* str, int len)
    {
        this->str = str;
        this->len = len;
    }

    int getLeastDictStr()
    {
        int i, j, l;
        i = 0;
        j = 1;
        while(i<len && j < len)
        {
            for (l=0; l < len; l++)
                if (str[(i+l)%len]!=str[(j+l)%len]) break;
            if (l > len) break;
            if (str[(i+l)%len] > str[(j+l)%len])
                i += l + 1;
            else
                j += j + 1;
            if ( i==j ) j = i+1;
        }
        if (i < j) return i;
        return j;
    }

private:
    char* str;
    int len;
};
int main()
{
    char str[7] = "bbbbaa";
    int len = 6;
    Solution* solver = new Solution(str, 6);
    int index = solver->getLeastDictStr();
    std::cout << index  << ": " << str[index] << std::endl;
    print("Hello world!");
    return 0;
}
