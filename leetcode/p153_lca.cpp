#include <iostream>
#include "../common/tree/binary_tree.h"

using namespace common::tree;

class Solution
{
public:
    Node* lca(Node* root, Node* A1, Node* A2)
    {
        if (root == NULL || root == A1 || root == A2)
        {
            return root;
        }
        Node* left = lca(root->left, A1, A2);
        Node* right = lca(root->right, A1, A2);
        if (left != NULL && right != NULL)
        {
            return root;
        }
        return left != NULL ? left : right;
    };
};

int main()
{
    Node* A1 = new Node(1);
    Node* A2 = new Node(4);
    Node* root = new Node(5,
                          new Node(2,
                                   A1,
                                   new Node(3,
                                            NULL,
                                            A2)),
                          new Node(7,
                                   new Node(6),
                                   new Node(9,
                                            new Node(8),
                                            NULL)));
    PrettyPrint(root);
    Solution solution;
    Node* lca = solution.lca(root, A1, A2);
    std::cout << lca->val << std::endl;
}
