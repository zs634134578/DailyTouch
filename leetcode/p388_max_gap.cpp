#include <iostream>
#include <vector>
#include "../common/array.h"

class Solution
{
public:
    int maxGap(std::vector<int>& nums)
    {
        int size = nums.size();
        if (size == 0) return 0;
        int min = 0;
        int max = 0;
        for (auto num : nums)
        {
            min = std::min(min, num);
            max = std::max(max, num);
        }
        if (min == max) return 0;
        Bucket* buckets = new Bucket[size + 1];
        for (auto num : nums)
        {
            std::cout << "num: " << num << std::endl;
            int bucketId = getBucketId(num, size, max, min);
            Bucket* bucket = &buckets[bucketId];
            std::cout << "bucketId: " << bucketId << std::endl;
            std::cout << "max: " << bucket->max << std::endl;
            std::cout << "min: " << bucket->min << std::endl;
            bucket->min = bucket->hasNum ? std::min(bucket->min, num) : num;
            bucket->max = bucket->hasNum ? std::max(bucket->max, num) : num;
            bucket->hasNum = true;
        }
        int lastMax = 0; // prev non-empty bucket's max
        int bucketId = 0;
        int maxGap = 0;
        while (bucketId <= size)
        {
            Bucket* bucket = &buckets[bucketId];
            if (bucket->hasNum)
            {
                lastMax = bucket->max;
                break;
            }
            else
            {
                bucketId++;
            }
        }
        std::cout << "bucketId: " << bucketId << std::endl;
        for (bucketId++; bucketId <= size; bucketId++)
        {
            Bucket* bucket = &buckets[bucketId];
            if (bucket->hasNum)
            {
                maxGap = std::max(maxGap, bucket->max - lastMax);
                lastMax = bucket->max;
            }
        }
        delete[] buckets;
        return maxGap;
    }

private:
    int getBucketId(int num, int size, int max, int min)
    {
        return (num - min) * size / (max - min);
    }
    struct Bucket {
        Bucket() : hasNum(false), min(0), max(0)
        {}
        bool hasNum;
        int min;
        int max;
    };
};

int main()
{
    std::vector<int> nums = {9, 3, 1, 10};
    Solution solution;
    common::array::print(nums);
    std::cout << solution.maxGap(nums) << std::endl;
}
