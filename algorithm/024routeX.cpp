/*
 * 问题描述：
 *     输入一颗二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。
 *         从树的根节点开始往下一直到叶节点所经过的节点形成一条路径。
 */
 
#include <iostream>
#include <vector>
using namespace std;

struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
    BinaryTreeNode(int x, BinaryTreeNode* left, BinaryTreeNode* right)
        : m_nValue(x), m_pLeft(left), m_pRight(right){}
};

class Solution{
    public:
        void findRoute(BinaryTreeNode* root, int sum)
        {
            if (root == NULL )
                return;
               
            vector<BinaryTreeNode*> path;
            this->find(root, path, 0,  sum );
        } 
        
        void find(
            BinaryTreeNode* node, 
            vector<BinaryTreeNode*> path,
            int curSum,
            int sum
            ) 
        {
            curSum += node->m_nValue;
            path.push_back(node);

            bool isLeaf = node->m_pLeft == NULL
                && node->m_pRight == NULL;
                
            if (isLeaf && curSum == sum )
            {
                this->printRoute(path);
            }

            if (node->m_pLeft != NULL)
                find(node->m_pLeft, path, curSum, sum);
            if (node->m_pRight != NULL)
                find(node->m_pRight, path, curSum, sum);

            curSum -= node->m_nValue;
            path.pop_back();

        }
    void printRoute(vector<BinaryTreeNode*> path)
    {
        if (path.empty()){
            std::cout << "no route found" << std::endl;
            return;
        }
        for(vector<BinaryTreeNode*>::iterator it=path.begin(); it != path.end(); it++)
        {
            std::cout << (*it)->m_nValue << " ";
        }
        std::cout << std::endl;
    }
};

int main()
{
    BinaryTreeNode* root = new BinaryTreeNode(10,
            new BinaryTreeNode(5, 
                new BinaryTreeNode(4, NULL, NULL), 
                new BinaryTreeNode(7, NULL, NULL)),
            new BinaryTreeNode(12, NULL, NULL));
    Solution* solver = new Solution();
    solver->findRoute(root, 22);
    std::cout << "Hello world" << std::endl;
    return 0;
}
