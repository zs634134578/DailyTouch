#include <iostream>
#include <assert.h>
#include "../common/list/list.h"


class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL)
            return NULL;
        ListNode* endNode = head;
        while (endNode->next != NULL)
            endNode = endNode->next;
        return mergeSort(head, NULL);
    }
private:
    ListNode* mergeSort(ListNode* startNode,
                        ListNode* endNode)
    {
        if (startNode == NULL)
            return startNode;
        ListNode* midNode = findMidNode(startNode, endNode);
        if (midNode == NULL)
            return startNode;
        mergeSort(startNode, midNode);
        mergeSort(midNode->next, endNode);
        return mergeList(startNode, midNode, endNode);
    }
    ListNode* findMidNode(ListNode* startNode,
                          ListNode* endNode)
    {
        if (startNode == NULL)
        {
            return NULL;
        }
        ListNode* pOneStep = startNode;
        ListNode* pTwoStep = startNode;
        while (pTwoStep != NULL
               && pTwoStep != endNode
               && pTwoStep->next != NULL)
        {
            pTwoStep = pTwoStep->next->next;
            pOneStep = pOneStep->next;
        }
        return pOneStep;
    }
    ListNode* mergeList(ListNode* startNode,
                        ListNode* midNode,
                        ListNode* endNode)
    {
        if (startNode == NULL || midNode == NULL)
            return NULL;
        assert(endNode != NULL);
        ListNode* p1 = startNode;
        ListNode* p2 = midNode->next;
        ListNode* pHead = NULL;
        ListNode* pCur = NULL;
        while (p1 != NULL
               && p2 != NULL
               && p1 != midNode->next
               && p2 != endNode->next)
        {
            if (p1->val <= p2->val)
                pCur = p1;
            else
                pCur = p2;
            if (pHead == NULL)
                pHead = pCur;
            pCur = pCur->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        while (p1 != NULL)
        {
            pCur = p1;
            pCur = pCur->next;
            p1 = p1->next;
        }
        while (p2 != NULL)
        {
            pCur = p2;
            pCur = pCur->next;
            p2 = p2->next;
        }
        return pHead;
    }
};


int main()
{
    ListNode* head = new ListNode(6,
            new ListNode(2,
                new ListNode(9,
                    new ListNode(3,
                        new ListNode(8,
                            new ListNode(5,
                                new ListNode(4,
                                    new ListNode(1,
                                        new ListNode(7)))))))));
    PrintList(head);
    Solution solution;
    ListNode* sortedList = solution.sortList(head);
    PrintList(sortedList);
}
