#include <iostream>
#include "../common/tree/binary_tree.h"

using namespace common::tree;

class Solution
{
public:
    Node* sortedArrayToBST(const std::vector<int>& ivec)
    {
        Node* root = NULL;
        convert(root, ivec, 0, ivec.size() - 1);
        return root;
    }
private:
    void convert(Node* &root,
                 const std::vector<int>& ivec,
                 int start,
                 int end)
    {
        if (start > end) return;
        int mid = (start + end) / 2;
        root = new Node(ivec[mid]);
        convert(root->left, ivec, start, mid - 1);
        convert(root->right, ivec, mid + 1, end);
    }
};

int main()
{
    std::vector<int> ivec = {1, 2, 3, 4, 5, 6, 7};
    Solution solution;
    Node* root = solution.sortedArrayToBST(ivec);
    PrettyPrint(root);
}
