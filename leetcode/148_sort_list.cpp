#include <iostream>
#include <assert.h>
#include "../common/list/list.h"


class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL)
            return NULL;
        return mergeSort(head);
    }
private:
    ListNode* mergeSort(ListNode* head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* midNode = findMidNode(head);
        ListNode* head1 = head;
        ListNode* head2 = midNode->next;
        midNode->next = NULL; // split up list
        head1 = mergeSort(head1);
        head2 = mergeSort(head2);
        return mergeList(head1, head2);
    }
    ListNode* findMidNode(ListNode* head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode* pOneStep = head;
        ListNode* pTwoStep = head->next;
        while (pTwoStep != NULL
               && pTwoStep->next != NULL)
        {
            pTwoStep = pTwoStep->next->next;
            pOneStep = pOneStep->next;
        }
        return pOneStep;
    }
    ListNode* mergeList(ListNode* head1,
                        ListNode* head2)
    {
        if (head1 == NULL)
            return head2;
        if (head2 == NULL)
            return head1;
        ListNode* p1 = head1;
        ListNode* p2 = head2;
        ListNode* pHead = new ListNode(0);
        ListNode* pCur = pHead;
        while (p1 != NULL
               && p2 != NULL)
        {
            if (p1->val <= p2->val)
            {
                pCur->next = p1;
                p1 = p1->next;
            }
            else
            {
                pCur->next = p2;
                p2 = p2->next;
            }
            pCur = pCur->next;
        }
        while (p1 != NULL)
        {
            pCur->next = p1;
            pCur = pCur->next;
            p1 = p1->next;
        }
        while (p2 != NULL)
        {
            pCur->next = p2;
            pCur = pCur->next;
            p2 = p2->next;
        }
        return pHead->next;
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
