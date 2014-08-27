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
        void reorderList(ListNode* head)
        {
            if( head == NULL 
                    || head->next == NULL
                    || head->next->next == NULL)
                return; 

            ListNode* mid = head, *tail = head;
            
            while( mid != NULL 
                    && mid->next != NULL
                    && tail != NULL
                    && tail->next != NULL
                    && tail->next->next != NULL)
            {
                mid = mid->next;
                tail = tail->next->next;
            }
            ListNode* pre, *pretail;
            pre = tail = head;
          
            while( pre != mid )
            {
                pretail = head;

                while(tail->next != NULL)
                    tail = tail->next;
                while(pretail->next->next != NULL)
                    pretail = pretail->next;

                tail->next = pre->next;
                pre->next = tail;
                pre = tail->next;
                pretail->next = NULL;
            }

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
    printList(head);
    test1(head);
}

int main()
{
    test2(4);
    std::cout << "Hello world!" << std::endl;
    return 0;
}
