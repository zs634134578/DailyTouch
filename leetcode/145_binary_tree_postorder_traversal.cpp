#include <iostream>
#include <vector>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> stack2;
        std::stack<TreeNode*> stack1;
        if (root == NULL) return result;
        stack1.push(root);
        while (!stack1.empty())
        {
            TreeNode* cur = stack1.top();
            stack1.pop();
            stack2.insert(stack2.begin(), cur->val);
            if (cur->left != NULL) stack1.push(cur->left);
            if (cur->right != NULL) stack1.push(cur->right);
        }
        return stack2;
    }
};

int main()
{
    return 0;
}
