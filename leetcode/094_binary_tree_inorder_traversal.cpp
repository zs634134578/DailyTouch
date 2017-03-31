#include <iostream>
#include <vector>
#include <stack>

/**
 *
 *  * Definition for a binary tree node.
 *
 *   * struct TreeNode {
 *
 *    *     int val;
 *
 *     *     TreeNode *left;
 *
 *      *     TreeNode *right;
 *
 *       *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *
 *        * };
 *
 *         */

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;
        if (root == NULL) return result;
        TreeNode* curNode = root;
        std::stack<TreeNode*> stack;
        do {
            if (curNode == NULL)
            {
                result.push_back(stack.top()->val);
                curNode = stack.top()->right;
                stack.pop();
            }
            else
            {
                stack.push(curNode);
                curNode = curNode->left;
            }
        } while (!stack.empty());
        return result;
    }
};

int main()
{
    return 0;
}
