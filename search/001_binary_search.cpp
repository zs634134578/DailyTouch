#include <iostream>
#include <glog/logging.h>

class BinarySearch
{
public:
    BinarySearch()
    {}
    int search(const std::vector<int>& datas,
               const int dest);
private:
    int searchInternal(const std::vector<int>& datas,
                       const int startIndex,
                       const int endIndex,
                       const int dest);
};

int BinarySearch::search(const std::vector<int>& datas,
                         const int dest)
{
    LOG(INFO) << "Enter: " << __func__;
    int ret = -1;
    ret = searchInternal(datas, 0, datas.size() - 1, dest);
    LOG(INFO) << "Leave: " << __func__;
    return ret;
}

int BinarySearch::searchInternal(const std::vector<int>& datas,
                                 const int startIndex,
                                 const int endIndex,
                                 const int dest)
{
    if (startIndex > endIndex)
    {
        LOG(INFO) << "Not Found Dest: " << dest;
        return -1;
    }
    int mid = startIndex + (endIndex - startIndex) / 2;
    if (datas[mid] == dest)
    {
        return mid;
    }
    else if (datas[mid] > dest)
    {
        return searchInternal(datas, startIndex, mid - 1, dest);
    }
    else
    {
        return searchInternal(datas, mid + 1, endIndex, dest);
    }
}

int main()
{
    BinarySearch binarySearch;
    int ret = -1;
    {
        std::vector<int> datas;
        int dest = 3;
        ret = binarySearch.search(datas, dest);
        LOG_IF(INFO, ret == -1) << "Case 1 Pass";
        CHECK(ret == -1) << "Case 1 Failed, Dest Not Found:" << dest;
    }
    {
        int dataArr[] = {1};
        std::vector<int> datas(dataArr, dataArr + 1);
        int dest = 3;
        ret = binarySearch.search(datas, dest);
        LOG_IF(INFO, ret == -1) << "Case 2 Pass";
        CHECK(ret == -1) << "Case 2 Failed, Dest Not Found:" << dest;
    }
    return 0;
}
