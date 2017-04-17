#include "binary_tree.h"

namespace common
{
namespace tree
{

char* Node::ToString()
{
    char* str = new char[32];
    sprintf(str, "%d", val);
    return str;
}

int Height(Node* root, int h)
{
    if (root == NULL)
    {
        return h;
    }
    return std::max(Height(root->left, h + 1), Height(root->right, h + 1));
}

void PrettyPrint(Node* root)
{
    int nodeLen = 17; // each node width
    printBinaryTree(root, 0, 'H', nodeLen);
}

void printBinaryTree(Node* node, int level, char flag, int nodeLen)
{
    if (node == NULL)
    {
        return;
    }
    printBinaryTree(node->right, level + 1, 'v', nodeLen);
    printNodeWithSpecificWidth(node, level, flag, nodeLen);
    printBinaryTree(node->left, level + 1, '^', nodeLen);
}

void printNodeWithSpecificWidth(Node* node, int level,
                                char flag, int nodeLen)
{
    // print space
    for (int i = 0; i < level * nodeLen; ++i)
    {
        std::cout << " ";
    }
    // add flag
    char nodeStr[32];
    sprintf(nodeStr, "%c%d%c", flag, node->val, flag);
    int len = strlen(nodeStr);
    int spaceCount = (nodeLen - len) / 2 + 1;
    for (int i = 0; i < spaceCount; ++i)
    {
        std::cout << " ";
    }
    std::cout << nodeStr;
    for (int i = 0; i < spaceCount; ++i)
    {
        std::cout << " ";
    }
    std::cout << std::endl;
}

std::string Serialize(Node* node)
{
    if (node == NULL)
    {
        return "#!";
    }
    std::string nodeStr(node->ToString());
    nodeStr.append("!");
    nodeStr += Serialize(node->left);
    nodeStr += Serialize(node->right);
    return nodeStr;
}

Node* DeSerialize(const std::string& seriaStr)
{
    size_t startPos = 0;
    std::queue<std::string> nodeQueue;
    size_t prevBoundary = 0;
    size_t nextBoundary = 0;
    const char* boundary = "!";
    nextBoundary = seriaStr.find(boundary, prevBoundary);
    while ((nextBoundary = seriaStr.find(boundary, prevBoundary))
            != std::string::npos)
    {
        nodeQueue.push(seriaStr.substr(prevBoundary, nextBoundary - prevBoundary));
        prevBoundary = nextBoundary + 1;
    }
    return deSerializeImp(nodeQueue);
}

Node* deSerializeImp(std::queue<std::string>& nodeQueue)
{
    if (nodeQueue.empty() || 
        nodeQueue.front() == "#")
    {
        nodeQueue.pop();
        return NULL;
    }
    Node* node = new Node(atoi(nodeQueue.front().c_str()));
    nodeQueue.pop();
    node->left = deSerializeImp(nodeQueue);
    node->right = deSerializeImp(nodeQueue);
    return node;
}

}
}

