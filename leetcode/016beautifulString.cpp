/*
 *
 */

#include<iostream>
#include<string>
#include<map>

using namespace std;

#define debug(x, y) std::cout << "(debug)" << x << y << std::endl;
#define print(x) std::cout << x << std::endl;

class Solution
{
public:

    bool mapAnalyzer(map<char, int> &chMap)
    {
        int size = chMap.size();
        map<char, int>::iterator it = chMap.begin();

        if ( size < 3)
            return false;
        else
        {
            for( it = chMap.begin(); it != chMap.end();)
            {
                char first = it->first;
                char second = (++it)->first;
                char third = (++it)->first;
                
                if ( first + 1 == second
                        && first + 2 == third)
                {
                    chMap[second] -= chMap[first];
                    chMap[third] -= chMap[first];
                    if ( chMap[second] == 0
                        && chMap[third] == 0)
                        return true;
                    else if ( chMap[second] < 0 || chMap[third] < 0)
                    {
                        chMap[second] += chMap[first];
                        chMap[third] += chMap[third];
                    }
                    else
                        ;
                }
                it--;
            }
            return false;
        }
    }

    void isBeautiful(const string& str, int len)
    {
        if (len <= 0)
        {
            std::cout << "NO" << std::endl;
            return;
        }

        map<char, int> chMap;
        for(int i = 0; i < len; i++)
        {
            if (chMap.count(str[i]) > 0)
                chMap[str[i]] += 1;
            else
                chMap[str[i]] = 1;
        }
        if (mapAnalyzer(chMap))
            std::cout << "YES" << std::endl;
        else 
            std::cout << "NO" << std::endl;

    }

};
int main()
{
    int len;
    cin >> len;
    string str;
    cin >> str;
    debug("str", str);
    Solution* solver = new Solution();
    solver->isBeautiful(str, len);
    return 0;
}
