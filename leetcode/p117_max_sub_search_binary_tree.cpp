
/*
 * Not Completed
 * */

#include "../common/tree/binary_tree.h"

#include <iostream>

using namespace common::tree;

class Solution
{
public:
    Node* MaxSearchBinarySubTree(Node* root)
    {
        int subTreeNodeCount = 0;
        int maxNodeCount = 0;
        Node* maxSubTreeRoot = NULL;
        if (isValidSeachBinaryTree(root, subTreeNodeCount, maxNodeCount, maxSubTreeRoot))
        {
            return maxSubTreeRoot;
        }
        return NULL;
    }
private:
    bool isValidSearchBinaryTree(Node* node,
            int& curNodeCount,
            int& maxNodeCount,
            Node* maxSubTreeRoot)
    {
        if (node == NULL)
        {
            return true;
        }
        bool left = isValidSearchBinaryTree(node->left, curNodeCount + 1, maxNodeCount, maxSubTreeRoot);
        bool right = isValidSearchBinaryTree(node->right, curNodeCount + 1,maxNodeCount, maxSubTreeRoot);
        bool cur = false;
        if (left && right
            && (node->left == NULL || node->val >= node->left->val)
            && (node->right == NULL || node->val <= node->right->val))
        {
            cur = true;
            curNodeCount = leftCount + rightCount + 1;
            if (curNodeCount > maxNodeCount)
            {
                maxNodeCount = curNodeCount;
                maxSubTreeRoot = node;
            }
            return true;
        }
    }
};


int main()
{
    return 0;
}
