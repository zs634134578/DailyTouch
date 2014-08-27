#include <iostream>
using namespace std;


int main()
{
    std::pair<int, char> p = std::make_pair(42, '0');
    std::cout << p.first << ": " << p.second << std::endl;
    return 0;
}
