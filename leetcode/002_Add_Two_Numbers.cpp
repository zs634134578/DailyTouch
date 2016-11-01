#include <iostream>

#include "../common/list/list.h"

class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        if (l1 == NULL && l2 == NULL)
        {
            return new ListNode(0);
        }
        if (l1 == NULL)
        {
            return l2;
        }
        if (l2 == NULL)
        {
            return l1;
        }
        ListNode* result = NULL;
        ListNode* pL1 = l1;
        ListNode* pL2 = l2;
        ListNode* pResult = NULL;
        int flag = 0;
        while (pL1 != NULL && pL2 != NULL)
        {
            int curNodeVal = (pL1->val + pL2->val + flag) % 10;
            flag = (pL1->val + pL2->val + flag) / 10;
            ListNode* curNode = new ListNode(curNodeVal);
            if (result == NULL)
            {
                result = curNode;
                pResult = curNode;
            }
            else
            {
                pResult->next = curNode;
                pResult = curNode;
            }
            pL1 = pL1->next;
            pL2 = pL2->next;
        }
        while (pL1 != NULL)
        {
            int curNodeVal = (pL1->val + flag) % 10;
            flag = (pL1->val + flag) / 10;
            ListNode* curNode = new ListNode(curNodeVal);
            pResult->next = curNode;
            pResult = pResult->next;
            pL1 = pL1->next;
        }
        while (pL2 != NULL)
        {
            int curNodeVal = (pL2->val + flag) % 10;
            flag = (pL2->val + flag) / 10;
            ListNode* curNode = new ListNode(curNodeVal);
            pResult->next = curNode;
            pResult = pResult->next;
            pL2 = pL2->next;
        }
        if (flag)
        {
            ListNode* curNode = new ListNode(flag);
            pResult->next = curNode;
        }
        return result;
    }
};

int main()
{
    /* Case: 1
    ListNode* l1 = new ListNode(2,
                                new ListNode(4,
                                             new ListNode(3)));
    ListNode* l2 = new ListNode(5,
                                new ListNode(6,
                                             new ListNode(4)));
    */

    /* Case: 2
    ListNode* l1 = new ListNode(5);
    ListNode* l2 = new ListNode(5);
    */

    /* Case: 3
    ListNode* l1 = new ListNode(9,
                                new ListNode(9));
    ListNode* l2 = new ListNode(1);
    */

    /* Case: 4
    ListNode* l1 = new ListNode(0);
    ListNode* l2 = new ListNode(7,
                                new ListNode(8));
    */

    /* Case 5 */
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(9,
                                new ListNode(9));
    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);
    PrintList(result);
    return 0;
}
