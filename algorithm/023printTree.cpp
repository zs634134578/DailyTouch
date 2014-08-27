/*
 * 问题描述：
 *     从上往下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。
 *
 */

#include <iostream>
#include <queue>
using namespace std;


#define debug(x) std::cout << x << std::endl;
struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
    BinaryTreeNode(int val, BinaryTreeNode* left, BinaryTreeNode* right):
        m_nValue(val), m_pLeft(left), m_pRight(right) {}
    BinaryTreeNode(int val) : m_nValue(val) {}
};

class Solution{
public:
    Solution(){
        this->treeQueue = new queue<BinaryTreeNode*>(); 
    }
    void printTreeWide(BinaryTreeNode* root)
    {
        if (root == NULL )
            return;

        treeQueue->push(root);
        BinaryTreeNode* front;
        while(treeQueue->size()!=0)
        {
            front = treeQueue->front();
            std::cout << front->m_nValue << " ";
            treeQueue->pop();
            if (front->m_pLeft) treeQueue->push(front->m_pLeft);
            if (front->m_pRight) treeQueue->push(front->m_pRight);
        }
        std::cout << std::endl;
    }

private:
    queue<BinaryTreeNode*> *treeQueue;
};
int main()
{
    BinaryTreeNode* root;
    root = new BinaryTreeNode(8,
            new BinaryTreeNode(6,
                new BinaryTreeNode(5),
                new BinaryTreeNode(7)),
            new BinaryTreeNode(10,
                new BinaryTreeNode(9),
                new BinaryTreeNode(11)));
    Solution* solver = new Solution();
    solver->printTreeWide(root);
    return 0;
}
