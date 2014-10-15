/*
 * 求a的n次幂，使用二分法加速
 */

#include <iostream>

using namespace std;

#define debug(x, y) std::cout << "(debug)" << x << y << std::endl;
#define print(x) std::cout << x << std::endl;

class Solution
{
public:
    Solution(int a, int n)
    {
        this->a = a;
        this->n = n;
    }
    int calculate()
    {
        int result = 1;
        int temp = 1;
        while( n != 0 )
        {
           if (temp == 1)
               temp = a;
           else 
               temp *= temp, n >>= 1;
           debug("temp:", temp);
           debug("n:", n);
        }
        return temp;
    }

private:
    int a;
    int n;

};
int main()
{
    Solution* solver = new Solution(2, 10);
    int result = solver->calculate();
    std::cout << result << std::endl;
    print("Hello world!");
    return 0;
}
