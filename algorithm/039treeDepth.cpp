/*
 *
 */

#include <iostream>

using namespace std;

#define debug(x, y) std::cout << "(debug)" << x << y << std::endl;
#define print(x) std::cout << x << std::endl;

struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;

    BinaryTreeNode(int value):m_nValue(value), m_pLeft(NULL), m_pRight(NULL){}
    BinaryTreeNode(int value, BinaryTreeNode* left, BinaryTreeNode* right):
        m_nValue(value), m_pLeft(left), m_pRight(right) {}
};

class Solution
{
public:
    int depth(BinaryTreeNode* root)
    {
        if (root == NULL)
            return 0;

        int depthLeft =  this->depth(root->m_pLeft);
        int depthRight = this->depth(root->m_pRight);

        return depthLeft >= depthRight ? depthLeft+1 : depthRight+1;
    }

};
int main()
{
    BinaryTreeNode *root = new BinaryTreeNode(1,
                   new BinaryTreeNode(2,
                        new BinaryTreeNode(4),
                        new BinaryTreeNode(5,
                            new BinaryTreeNode(7),
                            NULL)),
                   new BinaryTreeNode(3,
                        NULL,
                        new BinaryTreeNode(6)));
    Solution* solver = new Solution();

    int depth = solver->depth(root);
    print(depth);
    print("Hello world!");
    return 0;
}
