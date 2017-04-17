#include "stringUtility.h"
#include "stdio.h"


std::string ToString(int num)
{
}

void SplitToVec(const std::string& str,
                const std::string& boundary,
                std::vector<std::string>& strVec)
{
    if (str.length() == 0
        || boundary.length() == 0)
    {
        return;
    }
    size_t prev = 0;
    size_t next = 0;
    while ((next = str.find(boundary, prev)) != std::string::npos)
    {
        strVec.push_back(str.substr(prev, next - prev));
        prev = next + 1;
    }
    return;
}
