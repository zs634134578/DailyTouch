#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;

void print(vector<int> ivec)
{
    copy(ivec.begin(), ivec.end(), ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
}

void test1()
{
    int arr[5] = {1,2,3,4,5};
    vector<int> ivec;
    ivec.assign(arr, arr+5);
    print(ivec);
    vector<int>::reverse_iterator reit = ivec.rbegin();

    vector<int>::const_iterator ci = ivec.begin();
    vector<int>::iterator i(ivec.begin());
    advance(i, distance<vector<int>::const_iterator>(i, ci));
    ivec.insert(i, 7);
    print(ivec);
}


void test2()
{
    std::cout << "\nstart test2: " << std::endl;
    int arr[5] = {6, 7, 8, 9, 10};
    vector<int> ivec(arr, arr+5);
    typedef vector<int>::reverse_iterator revit;
    typedef vector<int>::iterator iter;
    revit i = ivec.rbegin() + 2;
    ivec.insert(--i.base(), 99);
    std::cout << *i  << std::endl;
    ivec.erase(--i.base());
    std::cout << *i  << std::endl;
}

int main()
{
    test1();
    test2();
    std::cout << "Hello world!" << std::endl;
    return 0;
}
