/*
 *
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 *
 * You must do this in-place without altering the nodes' values.
 *
 * For example,
 * Given {1,2,3,4}, reorder it to {1,4,2,3}.
 */

#include <iostream>

using namespace std;

#define debug(x, y) std::cout << "debug: " << x << y <<std::endl;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL) {}
    ListNode(int x, ListNode* next): val(x), next(next){}
};

void printList(ListNode* head);

class Solution {
    public:
        
        ListNode* getMid(ListNode* head)
        {
            ListNode* p,*q;
            p = head;
            q = head;
            while( q->next!= NULL && q->next->next!=NULL )
            {
                p = p->next;
                q = q->next->next;
            }
            return p;
        }

        ListNode*  reverse(ListNode* head)
        {
            ListNode *pre, *p, *q;
            pre = NULL;
            p = head;
            q = p->next;
            while(p!=NULL)
            {
                p->next = pre;
                pre = p;
                p = q;
                if(q!=NULL)
                    q = q->next;
            }
            return pre;
        }

        void merge(ListNode* p, ListNode* q)
        {
            ListNode* pNext, *qNext;
            ListNode* pCurr, *qCurr;
            pCurr = p;
            qCurr = q;
            pNext = p->next;
            qNext = q->next;
            while(pCurr!=NULL && qCurr!=NULL)
            {
                qCurr->next = pNext;
                pCurr->next = qCurr;
                qCurr = qNext;
                pCurr = pNext;
                if(qNext != NULL)
                    qNext = qNext->next;
                if(pNext != NULL)
                    pNext = pNext->next;
            }
            // pCurr->next = pNext;
        }
        
        void reorderList(ListNode* head)
        {
            if(head == NULL or head->next == NULL or head->next->next == NULL)
                return; 

            ListNode* mid = this->getMid(head);
            ListNode* q = this->reverse(mid->next);
            mid->next = NULL;
            merge(head, q);
        };
};

ListNode* getTestList(int i)
{
    ListNode* head, *cur;
    int j = 1;
    for(; j<=i; j++)
    {
       ListNode* node = new ListNode(j, NULL); 
       if ( j == 1)
       {
           head = node;
           cur = head;
       }
       else
       {
           cur->next = node;
           cur = node;
       }
    }
    return head;
}

void printList(ListNode* head)
{
    while(head != NULL)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

void test1(ListNode* head)
{
    Solution* solver = new Solution();
    solver->reorderList(head);
    printList(head);
}
void test2(int num)
{
    ListNode* head = getTestList(num);
    test1(head);
}

int main()
{
    test2(1);
    std::cout << "Hello world!" << std::endl;
    return 0;
}
