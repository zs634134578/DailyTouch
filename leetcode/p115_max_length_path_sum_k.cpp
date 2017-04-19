
#include "../common/tree/binary_tree.h"

#include <map>
#include <iostream>
#include <algorithm>

using namespace common::tree;

class Solution
{
public:
    int MaxLengthSumK(Node* root, int key)
    {
        // key: curSum, value: level
        std::map<int, int> sumMap;
        sumMap.insert(std::make_pair(0, 0));
        int maxPathLen = 0;
        int prevSum = 0;
        maxLengthInternal(root, 1, key, prevSum, maxPathLen, sumMap);
        return maxPathLen;
    }
private:
    void maxLengthInternal(Node* node,
                          int level,
                          int key,
                          int prevSum,
                          int& maxPathLen,
                          std::map<int, int>& sumMap)
    {
        if (node == NULL)
        {
            return;
        }
        int curSum = prevSum + node->val;
        auto curSumIt = sumMap.find(curSum);
        if (curSumIt == sumMap.end())
        {
            sumMap.insert(std::make_pair(curSum, level));
        }
        auto diffIt = sumMap.find(curSum - key);
        if (diffIt != sumMap.end())
        {
            maxPathLen = std::max(maxPathLen, level - diffIt->second);
        }
        maxLengthInternal(node->left, level + 1, key,
                          curSum, maxPathLen, sumMap);
        maxLengthInternal(node->right, level + 1, key,
                          curSum, maxPathLen, sumMap);
        if (sumMap[curSum] == level)
        {
            sumMap.erase(curSum);
        }
    }
};

int main()
{
    Node* root = new Node(-3,
                          new Node(3,
                                   new Node(1),
                                   new Node(0,
                                            new Node(1),
                                            new Node(6))),
                          new Node(-9,
                                   new Node(2),
                                   new Node(1)));
    PrettyPrint(root);
    Solution solution;
    std::cout << "Key: 6, maxLen: "
              << solution.MaxLengthSumK(root, 6)
              << std::endl;
    std::cout << "Key: -9, maxLen: "
              << solution.MaxLengthSumK(root, -9)
              << std::endl;
    std::cout << "Key: 1, maxLen: "
              << solution.MaxLengthSumK(root, 1)
              << std::endl;
    std::cout << "Key: -3, maxLen: "
              << solution.MaxLengthSumK(root, -3)
              << std::endl;
    return 0;
}
