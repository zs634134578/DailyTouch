/*
 *
 */

#include <iostream>

using namespace std;

#define debug(x, y) std::cout << "(debug)" << x << y << std::endl;
#define print(x) std::cout << x << std::endl;

class Solution
{
private:
    int dest;
public:
    Solution(int dest) : dest(dest) {}
    int getKeyNum(int *data, int len)
    {
        int num = 0;
        int indexStart = 0;
        int indexEnd = 0;
        
        indexStart = this->getStartIndex(data, 0, len-1);
        indexEnd = this->getEndIndex(data, 0, len-1);
        
        debug("startIndex:", indexStart);
        debug("endIndex:", indexEnd);
        num = indexEnd - indexStart + 1;
        return num;
    }

    int getStartIndex(int *data, int start, int end)
    {
        if (start == end)
        {
            if (data[start] == this->dest)
                debug("error:", start);
            return start;
        }
        if (start > end)
        {
            debug("error:",start );
            debug("error:",end);
            return -1;
        }

        int startIndex = 0;
        int mid = (start + end)/2;
        if (data[mid] == this->dest)
        {
            if (data[mid-1] == this->dest)
                startIndex = this->getStartIndex(data, start, mid-1);
            else
                startIndex = mid;
        }
        else if (data[mid] > this->dest)
            startIndex = this->getStartIndex(data, start, mid-1);
        else
            startIndex = this->getStartIndex(data, mid+1, end);
        
        return startIndex;
    }

    int getEndIndex(int *data, int start, int end)
    {
        if (start == end)
            return start;
        if (start > end)
        {
            debug("error:",start );
            debug("error:",end);
            return -1;
        }
        
        int endIndex = 0;
        int mid = (start + end)/ 2;
        if (data[mid] == this->dest)
        {
            if(data[mid+1] == this->dest)
                endIndex = this->getEndIndex(data, mid+1, end);
            else
                endIndex = mid;
        }
        else if(data[mid] > this->dest)
            endIndex = this->getEndIndex(data, start, mid-1);
        else
            endIndex = this->getEndIndex(data, mid+1, end);

        return endIndex;
    }
};
int main()
{
    int datas[8] = {1,2,3,3,3,3,4,5};
    int dest = 3;
    Solution* solver = new Solution(3);
    int num = solver->getKeyNum(datas, 8);
    print(num);
    print("Hello world!");
    return 0;
}
