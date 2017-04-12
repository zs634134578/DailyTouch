#include "binary_tree.h"

namespace common
{
namespace tree
{

int Height(Node* root, int h)
{
    if (root == NULL)
    {
        return h;
    }
    return std::max(Height(root->left, h + 1), Height(root->right, h + 1));
}

}
}

