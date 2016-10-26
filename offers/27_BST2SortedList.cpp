/*
 * 将二叉搜索树转换为排序双向链表
 *
 * 例如：
 *         10
 *        |  |
 *      6      14
 *     | |   |   |
 *    4   8  12  16
 * 
 *   4 = 6 = 8 = 10 = 12 = 14 = 16
 *
 * 算法：
 *   先序遍历二叉树
 *   每次记住前一次访问的节点
 *   访问当前节点时，将前一次访问的节点的右指针指向当前节点
 *
 * */

#include <iostream>

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

class Solution
{
public:
	void BST2SortedList(BinaryTreeNode* root);
private:
	void constructInternal(BinaryTreeNode* root, BinaryTreeNode** preNode);
};

BinaryTreeNode* Solution::BST2SortedList(BinaryTreeNode* root)
{
	if (root == NULL)
	{
		return NULL;
	}
	constructInternal(root, NULL);
}

int main()
{
	return 0;
}
