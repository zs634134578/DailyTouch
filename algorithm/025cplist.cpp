#include<iostream>
using namespace std;

struct ComplexListNode
{
    int m_nValue;
    ComplexListNode* m_pNext;
    ComplexListNode* m_pSibling;
    ComplexListNode(int value,
        ComplexListNode* next=NULL, ComplexListNode* sibling=NULL):m_nValue(value) ,m_pNext(next), m_pSibling(sibling) {}
};

class Solution
{
    ComplexListNode* clone(ComplexListNode* root)
    {
        ComplexListNode* cproot;
        return cproot;
    }
    
};


ComplexListNode* genList()
{
    ComplexListNode* root  = new ComplexListNode(1);
    ComplexListNode* node1 = new ComplexListNode(2);
    ComplexListNode* node2 = new ComplexListNode(3);
    ComplexListNode* node3 = new ComplexListNode(4);
    ComplexListNode* node4 = new ComplexListNode(5);
    root->m_pNext = node1;
    root->m_pSibling = node2;

    node1->m_pNext = node2;
    node1->m_pSibling = node4;

    node2->m_pNext = node3;
    node3->m_pNext = node4;
    node3->m_pSibling = node1;
    return root;
}

int main()
{
    ComplexListNode* root = genList();
    ComplexListNode* cproot = new ComplexListNode(*root); 
    std::cout << root->m_pNext->m_nValue << std::endl;
    root->m_pNext = NULL;
    root = NULL;
    std::cout << cproot->m_pNext->m_nValue << std::endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}


