#include "../common/tree/binary_tree.h"

#include <iostream>
#include <vector>

using namespace common::tree;

class Solution
{
public:
    void PrintBoundary(Node* root)
    {
        int height = Height(root, 0);
        Node* boundaryMap[height][2] = {NULL};
        buildBoundaryMap(root, 0, boundaryMap);
        for (int i = 0; i < height; ++i)
        {
            std::cout << boundaryMap[i][0]->val << " ";
        }
        printNonBoundaryLeaf(root, 0, boundaryMap);
        for (int i = height - 1 ; i >= 0; --i)
        {
            if (boundaryMap[i][0] != boundaryMap[i][1])
            {
                std::cout << boundaryMap[i][1]->val << " ";
            }
        }
        std::cout << std::endl;
    }

private:
    void printNonBoundaryLeaf(Node* node, int level,
                              Node* boundaryMap[][2])
    {
        if (node == NULL) return;
        if (node->left == NULL && node->right == NULL
                && node != boundaryMap[level][0]
                && node != boundaryMap[level][1])
        {
            std::cout << node->val << " ";
        }
        printNonBoundaryLeaf(node->left, level + 1, boundaryMap);
        printNonBoundaryLeaf(node->right, level + 1, boundaryMap);
    }

    void buildBoundaryMap(Node* node, int level,
                          Node* boundaryMap[][2])
    {
        if (node == NULL) return;
        boundaryMap[level][0] = boundaryMap[level][0] == NULL ?
            node : boundaryMap[level][0];
        boundaryMap[level][1] = node;
        buildBoundaryMap(node->left, level + 1, boundaryMap);
        buildBoundaryMap(node->right, level + 1, boundaryMap);
    }

};

int main()
{
    Node* root = new Node(1,
            new Node(2,
                     NULL,
                     new Node(4,
                              new Node(7),
                              new Node(8,
                                       NULL,
                                       new Node(11,
                                                new Node(13),
                                                new Node(14))))),
            new Node(3,
                     new Node(5,
                              new Node(9,
                                       new Node(12,
                                                new Node(15),
                                                new Node(16)),
                                       NULL),
                              new Node(10)),
                     new Node(6)));
    Solution solution;
    solution.PrintBoundary(root);
    PrettyPrint(root);
    return 0;
}
