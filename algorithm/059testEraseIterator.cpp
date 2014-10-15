/*
 *
 */

#include <iostream>
#include <vector>
using namespace std;

#define debug(x, y) std::cout << "(debug)" << x << y << std::endl;
#define print(x) std::cout << x << std::endl;

class Solution
{
public:
    Solution()
    {
        int arr[6] = {1,2,2,3,4,5};
        for(int i = 0; i < 6; i++)
            this->ivec.push_back(arr[i]);
    }
    void test()
    {
        this->printVec();
        for(vector<int>::iterator it = ivec.begin();
            it != ivec.end();)
        {
            if( *it == 2)
            {
                debug("to erase: ", *it);
                it = ivec.erase(it);
                debug("after erase, *it = ", *it);
            }
            else
                it++;
        }
        this->printVec();
    }
    void printVec()
    {
        for(vector<int>::iterator it = this->ivec.begin();
        it != this->ivec.end();
        it++)
            std::cout << *it << ", ";
        std::cout << std::endl;
    }
private:
    vector<int> ivec;

};
int main()
{
    Solution* solver = new Solution();
    solver->test();
    print("Hello world!");
    return 0;
}
