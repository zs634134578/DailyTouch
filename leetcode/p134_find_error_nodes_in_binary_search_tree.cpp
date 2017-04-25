#include <iostream>
#include "../common/tree/binary_tree.h"

using namespace common::tree;

class Solution
{
public:
    std::vector<Node*> findErrorNodes(Node* root)
    {
        std::vector<Node*> errorNodes;
        if (root == NULL) return errorNodes;
        std::vector<Node*> midVisits;
        midVisit(root, midVisits);
        for_each(midVisits.begin(), midVisits.end(), [](Node* node){
                    std::cout << node->val << " ";
                });
        std::cout << std::endl;
        int timeOfDescend = 0;
        Node* prev = *(midVisits.begin());
        for (auto it = midVisits.begin() + 1; it != midVisits.end(); ++it)
        {
            if (prev->val > (*it)->val)
            {
                ++timeOfDescend;
                if (timeOfDescend == 1)
                {
                    errorNodes.push_back(prev);
                    errorNodes.push_back(*it);
                }
                else if (timeOfDescend == 2)
                {
                    errorNodes.pop_back();
                    errorNodes.push_back(*it);
                }
                else
                {
                    // There is more than 2 error nodes
                    errorNodes.clear();
                }
            }
            prev = *it;
        }
        return errorNodes;
    }
private:
    void midVisit(Node* node, std::vector<Node*>& midVisits)
    {
        if (node == NULL)
        {
            return;
        }
        midVisit(node->left, midVisits);
        midVisits.push_back(node);
        midVisit(node->right, midVisits);
    }
};

int main()
{
    Node* root = new Node(5,
                          new Node(2,
                                   new Node(1),
                                   new Node(8,
                                            NULL,
                                            new Node(4))),
                          new Node(7,
                                   new Node(6),
                                   new Node(9,
                                            new Node(3),
                                            NULL)));
    PrettyPrint(root);
    Solution solution;
    auto results = solution.findErrorNodes(root);
    for_each(results.begin(), results.end(), [](Node* result){
                std::cout << result->val << std::endl;
            });
    return 0;
}
