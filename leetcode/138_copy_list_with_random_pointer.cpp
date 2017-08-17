#include <iostream>

#include "../common/list/list.h"

class Solution
{
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL)
        {
            return head;
        }
        // step 1: copy each node and insert to next
        RandomListNode* cur = head;
        RandomListNode* next = NULL;
        while (cur != NULL)
        {
            next = cur->next;
            RandomListNode* dupNode = new RandomListNode(cur->label);
            cur->next = dupNode;
            dupNode->next = next;
            cur = next;
        }
        // step 2: dup random pointer
        cur = head;
        while (cur != NULL)
        {
            cur->next->random = cur->random != NULL ? cur->random->next : NULL;
            cur = cur->next->next;
        }
        // step 3: split new list
        RandomListNode* newHead = head->next;
        RandomListNode* newCur = NULL;
        cur = head;
        while (cur != NULL)
        {
            next = cur->next->next;
            newCur = cur->next;
            cur->next = next;
            newCur->next = next != NULL ? next->next : NULL;
            cur = next;
        }
        return newHead;
    }
};

int main()
{
    RandomListNode* node1 = new RandomListNode(1);
    RandomListNode* node2 = new RandomListNode(2);
    RandomListNode* node3 = new RandomListNode(3);
    RandomListNode* node4 = new RandomListNode(4);
    RandomListNode* node5 = new RandomListNode(5);
    node1->SetNext(node2);
    node2->SetNext(node3);
    node3->SetNext(node4);
    node4->SetNext(node5);
    node1->SetRandom(node3);
    node2->SetRandom(node4);
    node3->SetRandom(node5);
    node4->SetRandom(node1);
    node5->SetRandom(node2);
    PrintList<RandomListNode>(node1);
    Solution solution;
    RandomListNode* newHead = solution.copyRandomList(node1);
    PrintList<RandomListNode>(newHead);
    return 0;
}
