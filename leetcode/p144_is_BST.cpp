#include <iostream>
#include <stdlib.h>
#include <algorithm>

#include "../common/tree/binary_tree.h"

using namespace common::tree;

class Solution {
public:

    /**
     *
     * @param root: The root of binary tree.
     *
     * @return: True if this Binary tree is Balanced, or false.
     *
     **/

    bool isBalanced(Node *root) {
        bool result = false;
        isBalancedInternal(root, 1, result);
        return result;
    }
private:
    int isBalancedInternal(Node* node, int height, bool& result)
    {
        if (node == NULL)
        {
            result = true;
            return height;
        }
        int leftHeight = isBalancedInternal(node->left, height + 1, result);
        if (!result)
        {
            result = false;
            return height;
        }
        int rightHeight = isBalancedInternal(node->right, height + 1, result);
        if (!result)
        {
            result = false;
            return height;
        }
        result = (abs(leftHeight - rightHeight) <= 1);
        return std::max(leftHeight, rightHeight);
    }
};

int main()
{
    Node* root = new Node(5,
                          new Node(2,
                                   new Node(1),
                                   new Node(8,
                                            NULL,
                                            new Node(4))),
                          new Node(7,
                                   new Node(6),
                                   new Node(9,
                                            new Node(3),
                                            NULL)));
    PrettyPrint(root);
    Solution solution;
    std::cout << solution.isBalanced(root) << std::endl;
    return 0;
}
