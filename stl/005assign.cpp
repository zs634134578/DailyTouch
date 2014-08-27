#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

void print(vector<int> v)
{
    for(vector<int>::iterator it=v.begin(); it!=v.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
void test1()
{
    vector<int> v1(10, 1), v2(30,2);
    print(v1);

    v1.clear();
    v1.assign(v2.begin()+v2.size()/2, v2.end());
    print(v1);

    int array[20] = {3};
    v1.insert(v1.end(), array, array+20);
    print(v1);

    v1.erase(remove(v1.begin(), v1.end(), 3), v1.end());
    print(v1);
}

int main()
{
    test1();
    return 0;
}
