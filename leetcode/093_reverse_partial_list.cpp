#include <iostream>
#include "../common/list/list.h"

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int len = length(head);
        if (m > len || n > len || m > n)
        {
            return head;
        }
        ListNode* prev = NULL;     // keep prev node of sub list
        ListNode* substart = NULL;
        ListNode* cur = head;
        ListNode* next = NULL;
        ListNode* newHead = head;
        int count = 1;
        while (count <= m || count <= n)
        {
            if (count < m)
            {
                prev = cur;
                cur = cur->next;
            }
            else if (count == m)
            {
                substart = prev;
                next = cur->next;
                prev = cur;
                cur = cur->next;
            }
            else if (count > m && count < n)
            {
                next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }
            else if (count == n)
            {
                if (substart == NULL)
                {
                    head->next = cur->next;
                    newHead = cur;
                }
                else
                {
                    substart->next->next = cur->next;
                    substart->next = cur;
                }
                cur->next = prev;
            }
            ++count;
        }
        return newHead;
    }
private:
    int length(ListNode* head)
    {
        if (head == NULL)
        {
            return 0;
        }
        int len = 0;
        while (head != NULL)
        {
            ++len;
            head = head->next;
        }
        return len;
    }
};

int main()
{
    Solution solution;
    ListNode* list1 = new ListNode(1,
            new ListNode(2,
                new ListNode(3,
                    new ListNode(4,
                        new ListNode(5)))));
    PrintList(list1);
    int from1 = 2;
    int to1 = 4;
    ListNode* result1 = solution.reverseBetween(list1, from1, to1);
    PrintList(result1);
    int from2 = 1;
    int to2 = 3;
    ListNode* result2 = solution.reverseBetween(list1, from2, to2);
    PrintList(result2);
}
