#include <iostream>
#include <glog/logging.h>

class BinarySearch
{
public:
    BinarySearch()
    {}
    int search1stGeNum(const std::vector<int>& datas,
               const int dest);
private:
    int searchInternal(const std::vector<int>& datas,
                       int startIndex,
                       int endIndex,
                       const int dest);
};

int BinarySearch::search1stGeNum(const std::vector<int>& datas,
                         const int dest)
{
    LOG(INFO) << "Enter: " << __func__;
    int ret = -1;
    ret = searchInternal(datas, 0, datas.size() - 1, dest);
    LOG(INFO) << "Leave: " << __func__;
    return ret;
}

int BinarySearch::searchInternal(const std::vector<int>& datas,
                                 int startIndex,
                                 int endIndex,
                                 const int dest)
{
    int ret = -1;
    int end = endIndex;
    while (startIndex <= endIndex)
    {
        int midIndex = startIndex + (endIndex - startIndex) / 2;
        if (datas[midIndex] >= dest)
        {
            endIndex = midIndex - 1;
        }
        else
        {
            startIndex = midIndex + 1;
        }
    }
    return startIndex <= end ? startIndex : -1;
}

int main()
{
    BinarySearch binarySearch;
    int ret = -1;
    {
        std::vector<int> datas;
        int dest = 3;
        ret = binarySearch.search1stGeNum(datas, dest);
        LOG_IF(INFO, ret == -1) << "Case 1 Pass";
        CHECK(ret == -1) << "Case 1 Failed, Dest Not Found:" << dest << " ret:" << ret;
    }
    {
        int dataArr[] = {1};
        std::vector<int> datas(dataArr, dataArr + 1);
        int dest = 3;
        ret = binarySearch.search1stGeNum(datas, dest);
        LOG_IF(INFO, ret == -1) << "Case 2 Pass";
        CHECK(ret == -1) << "Case 2 Failed, Dest Not Found:" << dest;
    }
    {
        int dataArr[] = {1,2,3,4,5,6,7};
        std::vector<int> datas(dataArr, dataArr + 7);
        int dest = 5;
        ret = binarySearch.search1stGeNum(datas, dest);
        LOG_IF(INFO, ret == 4) << "Case 3 Pass";
        CHECK(ret == 4) << "Case 3 Failed, Dest Not Found:" << dest << " ret:" << ret;
    }
    {
        int dataArr[] = {1,2,3,5,6,7};
        std::vector<int> datas(dataArr, dataArr + 6);
        int dest = 4;
        ret = binarySearch.search1stGeNum(datas, dest);
        LOG_IF(INFO, ret == 3) << "Case 4 Pass";
        CHECK(ret == 3) << "Case 4 Failed, Dest Not Found:" << dest << " ret:" << ret;
    }
    {
        int dataArr[] = {1,2,3,6,6,6,7};
        std::vector<int> datas(dataArr, dataArr + 7);
        int dest = 6;
        ret = binarySearch.search1stGeNum(datas, dest);
        LOG_IF(INFO, ret == 3) << "Case 5 Pass";
        CHECK(ret == 3) << "Case 5 Failed, Dest Not Found:" << dest;
    }
    {
        int dataArr[] = {6, 6, 6, 6, 6, 6, 6};
        std::vector<int> datas(dataArr, dataArr + 7);
        int dest = 6;
        ret = binarySearch.search1stGeNum(datas, dest);
        LOG_IF(INFO, ret == 0) << "Case 6 Pass";
        CHECK(ret == 0) << "Case 6 Failed, Dest Not Found:" << dest << " ret:" << ret;
    }
    return 0;
}
