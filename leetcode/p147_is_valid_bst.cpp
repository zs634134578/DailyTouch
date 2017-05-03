#include <iostream>
#include "../common/tree/binary_tree.h"

using namespace common::tree;

class Solution
{
public:
    bool isValidBST(TreeNode* root)
    {
        TreeNode* prev = NULL;
        return isBST(root, &prev);
    }
private:
    bool isBST(TreeNode* node,
               TreeNode** prev)
    {
        if (node == NULL)
        {
            return true;
        }
        bool res = false;
        res = isBST(node->left, prev);
        if (!res)
        {
            return res;
        }
        if (*prev != NULL)
        {
            res = node->val > (*prev)->val;
            if (!res)
            {
                return res;
            }
        }
        *prev = node;
        return isBST(node->right, prev);
    }
};

int main()
{
    TreeNode* root = new TreeNode(5,
                          new TreeNode(2,
                                   new TreeNode(1),
                                   new TreeNode(3,
                                            NULL,
                                            new TreeNode(4))),
                          new TreeNode(7,
                                   new TreeNode(6),
                                   new TreeNode(9,
                                            new TreeNode(8),
                                            NULL)));
    PrettyPrint(root);
    Solution solution;
    std::cout << solution.isValidBST(root) << std::endl;
    return 0;
}
