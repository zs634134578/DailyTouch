#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define debug(x, y) std::cout << x << y << std::endl;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
};

class Solution {
    public:
        vector<int> postorderTraversal( TreeNode *root ){
            vector<int> postorderlist;

            if ( root == NULL )
            {
                return postorderlist;
            }

            stack<TreeNode*> tmpStack1, tmpStack2;
            TreeNode* curr;
            int tmp;
            tmpStack1.push(root);

            while(!tmpStack1.empty())
            {
                curr = tmpStack1.top();
                tmpStack1.pop();
                tmpStack2.push(curr);
                if(curr->left) tmpStack1.push(curr->left);
                if(curr->right) tmpStack1.push(curr->right);
            }
            while(!tmpStack2.empty())
            {
                postorderlist.push_back(tmpStack2.top()->val);
                tmpStack2.pop();
            }
            return postorderlist;
        }
};

int main()
{
    TreeNode* root = new TreeNode(1,
            new TreeNode(2,
                new TreeNode(4),
                new TreeNode(5)),
            new TreeNode(3,
                new TreeNode(6),
                new TreeNode(7)));
    Solution* solver = new Solution();
    TreeNode* root1 = NULL;
    vector<int> result = solver->postorderTraversal(root1);
    for(vector<int>::iterator it = result.begin(); it!=result.end(); it++ )
        std::cout << *it << " ";
    std::cout << std::endl;
    return 0;
}
