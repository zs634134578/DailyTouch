#include <iostream>
#include "../common/tree/binary_tree.h"

using namespace common::tree;

class Solution
{
public:
    bool Contains(Node* root1, Node* root2)
    {
        if (root1 == NULL || root2 == NULL)
        {
            return root1 == NULL ? root2 == NULL : true;
        }
        bool result = false;
        if (root1->val == root2->val)
        {
            result = Contains(root1->left, root2->left)
                     && Contains(root1->right, root2->right);
        }
        else
        {
            result = Contains(root1->left, root2)
                     || Contains(root1->right, root2);
        }
        return result;
    }
};

int main()
{
    Node* root1 = new Node(5,
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
    Node* root2 = new Node(7,
                           new Node(6),
                           new Node(9));
    Solution solution;
    std::cout << solution.Contains(root1, root2) << std::endl;
    return 0;
}
