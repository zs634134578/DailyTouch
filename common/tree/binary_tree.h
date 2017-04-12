#include <algorithm>

namespace common
{
namespace tree
{
struct Node
{
    int val;
    Node* left;
    Node* right;
    
    Node(int val_)
        : val(val_), left(NULL), right(NULL)
    {}
    Node(int val_, Node* left_, Node* right_)
        : val(val_), left(left_), right(right_)
    {}
};

void Print(Node* root);
int Height(Node* root, int h);
}
}


