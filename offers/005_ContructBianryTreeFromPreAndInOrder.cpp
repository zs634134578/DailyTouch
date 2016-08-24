/**
 *
 * Definition for a binary tree node.
 *
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 **/
#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG(key, value) std::cout << "[DEBUG]: " << __LINE__ << " " << key << " " << value << std::endl;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

public:

    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder);
	void PrintTreeInPreorder(TreeNode* tree);

private:
	TreeNode* constructCore(std::vector<int>& preorder,
							int curRootIndexPreOrder,
							std::vector<int>& inorder,
							int startIndex, int endIndex);

};

TreeNode* Solution::constructCore(std::vector<int>& preorder,
								  int curRootIndexPreOrder,
								  std::vector<int>& inorder,
								  int startIndex, int endIndex)
{
	int curRootValue = preorder[curRootIndexPreOrder];
	TreeNode* curRootNode = new TreeNode(curRootValue);
	if (startIndex == endIndex)
	{
		return curRootNode;
	}
	std::vector<int>::const_iterator it = std::find(inorder.begin() + startIndex, inorder.begin() + endIndex, curRootValue);
	int curRootIndexInorder = it - inorder.begin(); 
	if (startIndex < curRootIndexInorder)
	{
		curRootNode->left = constructCore(preorder, curRootIndexPreOrder + 1,
				inorder, startIndex, curRootIndexInorder - 1);
	}
	if (endIndex > curRootIndexInorder)
	{
		curRootNode->right = constructCore(preorder, curRootIndexPreOrder + 1,
				inorder, curRootIndexInorder + 1, endIndex);
	}
	return curRootNode;
}

TreeNode* Solution::buildTree(std::vector<int>& preorder, std::vector<int>& inorder)
{
	if (preorder.size() == 0
		|| inorder.size() == 0
		|| preorder.size() != inorder.size())
	{
		return NULL;
	}
	return constructCore(preorder, 0, inorder, 0, preorder.size() - 1);

}

void Solution::PrintTreeInPreorder(TreeNode* tree)
{
	if (tree == NULL)
	{
		return;
	}
	std::cout << tree->val << " ";
	PrintTreeInPreorder(tree->left);
	PrintTreeInPreorder(tree->right);
}


int main()
{
	int preorderArray[] = {1, 2, 4, 7, 3, 5, 6, 8};
	int inorderArray[] = {4, 7, 2, 1, 5, 3, 8, 8};
	std::vector<int> preorder(preorderArray, preorderArray + sizeof(preorderArray)/sizeof(int));
	std::vector<int> inorder(inorderArray, inorderArray + sizeof(inorderArray)/sizeof(int));

	Solution solution;
	TreeNode* tree = solution.buildTree(preorder, inorder);
	solution.PrintTreeInPreorder(tree);
	std::cout << std::endl;
	
	return 0;
}
