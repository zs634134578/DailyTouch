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

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

public:

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);

};

TreeNode* Solution::buildTree(std::vector<int>& preorder, std::vector<int>& inorder)
{

}


int main()
{
	int preorderArray[] = {1, 2, 4, 7, 3, 5, 6, 8};
	int inorderArray[] = {4, 7, 2, 1, 5, 3, 8, 8};
	std::vector<int>& preorder(preorderArray, preorderArray + sizeof(preorderArray)/sizeof(int));
	std::vector<int>& inorder(inorderArray, inorderArray + sizeof(inorderArray)/sizeof(int));

	Solution solution;
	TreeNode* tree = solution.buildTree(preorder, inorder);

	return 0;
}
