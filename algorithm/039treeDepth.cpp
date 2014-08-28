/*
 *
 */

#include <iostream>
#include <cstdlib>

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

    bool isAVL(BinaryTreeNode* root)
    {
        if (root == NULL)
            return true;
        
        int leftDepth = this->depth(root->m_pLeft);
        int rightDepth = this->depth(root->m_pRight);
        if (abs(leftDepth - rightDepth) <= 1)
            return true && isAVL(root->m_pLeft) && isAVL(root->m_pRight);
        else
            return false;
    }
    bool isAVL(BinaryTreeNode* root, int* depth)
    {
        if (root == NULL)
        {
            *depth = 0;
            return true;
        }

        int left = 0, right = 0;
        if (this->isAVL(root->m_pLeft, &left)
                && this->isAVL(root->m_pRight, &right))
        {
            if (abs(left - right) <= 1)
            {
                int tmp = (left>=right ? left : right);
                *depth = 1 + tmp;                 
                return true;
            }
        }
        return false;
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
    int tmpDepth = 0;
    bool result = solver->isAVL(root, &tmpDepth);
    print(result);
    print("Hello world!");
    return 0;
}
