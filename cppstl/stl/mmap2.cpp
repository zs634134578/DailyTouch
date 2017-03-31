#include <iostream>
#include <map>

int main()
{
    std::multimap<int, std::string > mmap;
    mmap.insert(std::make_pair(1, "xyz"));
    mmap.insert(std::make_pair(2, "abc"));
    mmap.insert(std::make_pair(1, "def"));
    std::cout << mmap.find(1)->second << std::endl;
    return 0;
}
