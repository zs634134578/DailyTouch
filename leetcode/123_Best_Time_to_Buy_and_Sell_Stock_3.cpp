#include <iostream>
#include <vector>
#include <map>
#include <glog/logging.h>
#include <glog/stl_logging.h>

#define DEBUG(key, info) std::cout << "DEBUG: " << key << " - " << info << std::endl;

class Solution
{
private:
    // key: range [startIndex, endIndex]
    // value: max profit in this range
    std::map<std::pair<int, int>, int> mProfitCache;
private:
    int maxProfitInOneTransaction(std::vector<int>& prices, int startIndex, int endIndex)
    {
        std::map<std::pair<int, int>, int>::iterator it = mProfitCache.find(std::make_pair(startIndex, endIndex));
        if (it != mProfitCache.end())
        {
            return it->second;
        }
        int maxProfit = 0;
        for (int i = startIndex ; i <= endIndex - 1; ++i)
        {
            for (int j = i + 1; j <= endIndex; ++j)
            {
                int profit = prices[j] - prices[i];
                //DEBUG("profit", profit);
                maxProfit = profit > maxProfit ? profit : maxProfit;
            }
        }
        if (maxProfit < 0)
        {
            maxProfit = 0;
        }
        mProfitCache.insert(std::make_pair(std::make_pair(startIndex, endIndex), maxProfit));
        //DEBUG("startIndex", startIndex);
        //DEBUG("endIndex", endIndex);
        //DEBUG("maxProfit", maxProfit);
        return maxProfit;;
    }
public:
    int maxProfit(std::vector<int>& prices)
    {
        if (prices.size() < 2)
        {
            return 0;
        }
        int maxProfit = maxProfitInOneTransaction(prices, 0, prices.size() - 1);
        //DEBUG("maxProfit", maxProfit);
        for (int index = 1; index < prices.size() -2; ++index)
        {
            int curMaxProfit = maxProfitInOneTransaction(prices, 0, index) 
                               + maxProfitInOneTransaction(prices, index + 1, prices.size() - 1);
            //DEBUG("index", index);
            //DEBUG("curMaxProfit", curMaxProfit);
            maxProfit = curMaxProfit > maxProfit ? curMaxProfit : maxProfit;
        }
        return maxProfit;
    }
};

int main(int argc, char* argv[])
{
    google::InitGoogleLogging(argv[0]);
    FLAGS_log_dir = "./log";
    Solution solution;
    std::vector<int> prices; 
    prices.push_back(3);
    prices.push_back(2);
    prices.push_back(6);
    prices.push_back(5);
    prices.push_back(0);
    prices.push_back(3);
    LOG(INFO) <<  solution.maxProfit(prices) ;
    LOG(INFO) << prices;
    return 0;
}
