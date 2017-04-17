#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <queue>

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
    char* ToString();
};

void PrettyPrint(Node* root);
void printBinaryTree(Node* node, int level, char flag, int nodeLen);
void printNodeWithSpecificWidth(Node* node, int level,
                                char flag, int nodeLen);

// Serialize And Deserialize
std::string Serialize(Node* node);
Node* DeSerialize(const std::string& seriaStr);
Node* deSerializeImp(std::queue<std::string>& nodeQueue);

int Height(Node* root, int h);

} // tree
} // common


