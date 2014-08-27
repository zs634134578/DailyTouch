#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> constest(20, 1);
    std::cout << "constest capacity: " << constest.capacity() << std::endl;
    std::cout << "constest size: " << constest.size() << std::endl;
    constest.erase(constest.begin()+constest.size()/2, constest.end());
    std::cout << "constest capacity: " << constest.capacity() << std::endl;
    std::cout << "constest size: " << constest.size() << std::endl;
    vector<int>(constest).swap(constest);
    constest.clear();
    std::cout << "constest capacity: " << constest.capacity() << std::endl;
    std::cout << "constest size: " << constest.size() << std::endl;
    
    return 0;
}
