/**
 *
 *  * Definition of TreeNode:
 *
 *   * class TreeNode {
 *
 *    * public:
 *
 *     *     int val;
 *
 *      *     TreeNode *left, *right;
 *
 *       *     TreeNode(int val) {
 *
 *        *         this->val = val;
 *
 *         *         this->left = this->right = NULL;
 *
 *          *     }
 *
 *           * }
 *
 *            */

#include "../common/tree/binary_tree.h"

#include <iostream>
#include <vector>
#include <deque>

using namespace common::tree;

class Solution {

/**
 *
 * @param root: The root of binary tree.
 *
 * @return: A list of lists of integer include 
 *
 * the zigzag level order traversal of its nodes' values 
 *
 **/

public:
    std::vector<std::vector<int> > zigzagLevelOrder(Node* root) {
        std::vector<std::vector<int> > results;
        if (root == NULL) return results;
        int height = 1;
        int curLevelSize = 1;
        std::deque<Node*> deque;
        deque.push_back(root);
        while (!deque.empty())
        {
            std::vector<int> tmpResult;
            int nextLevelSize = 0;
            for (int i = 0; i < curLevelSize; ++i)
            {
                if (height % 2 == 1)
                {
                    Node* front = deque.front();
                    deque.pop_front();
                    tmpResult.push_back(front->val);
                    if (front->left != NULL)
                    {
                        deque.push_back(front->left);
                        ++nextLevelSize;
                    }
                    if (front->right != NULL)
                    {
                        deque.push_back(front->right);
                        ++nextLevelSize;
                    }
                }
                else
                {
                    Node* back = deque.back();
                    deque.pop_back();
                    tmpResult.push_back(back->val);
                    if (back->right != NULL)
                    {
                        deque.push_front(back->right);
                        ++nextLevelSize;
                    }
                    if (back->left != NULL)
                    {
                        deque.push_front(back->left);
                        ++nextLevelSize;
                    }
                }
            }
            curLevelSize = nextLevelSize;
            results.push_back(tmpResult);
            ++height;
        }
    }
};

int main()
{
    Node* root = new Node(-3,
                          new Node(3,
                                   new Node(1),
                                   new Node(0,
                                            new Node(1),
                                            new Node(6))),
                          new Node(-9,
                                   new Node(2),
                                   new Node(1)));
    PrettyPrint(root);
    Solution solution;
    std::vector<std::vector<int> > results = solution.zigzagLevelOrder(root);
    for_each(results.begin(), results.end(), [](std::vector<int>& ivec){
                for (auto it = ivec.begin(); it != ivec.end(); it++)
                {
                    std::cout << *it << " ";
                }
                std::cout << std::endl;
            });
    std::cout << std::endl;
    return 0;
}
