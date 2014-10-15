/*
 *
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define debug(x, y) std::cout << "(debug)" << x << y << std::endl;
#define print(x) std::cout << x << std::endl;

class Solution
{
public:
    Solution(int* arr, int len)
    {
        this->arr = arr;
        this->len = len;
    }
    void findGroup(int k)
    {
        int i, j;
        std::vector<int> ivec(this->arr, 0, len-1);
    }

    void doFind(int sum, int k) 
    {
        
    }

    static int comp(const void*a, const void* b)
    {
        return (*(int*)a) <= (*(int*)b);
    }

private:
    int* arr;
    int len;
};
int main()
{
    int arr[5] = {1,2,3,4,5};
    Solution* solver = new Solution(arr, 5);
    solver->findGroup(6);
    print("Hello world!");
    return 0;
}
