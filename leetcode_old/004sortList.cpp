#include <iostream>

#define debug(x, y) std::cout << "debug: " << x << "  " << y <<std::endl;
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode( int x, ListNode* next ) : val(x), next(next){}
    ListNode(  ) : val(0), next(NULL) {}
};

void printList(string info, ListNode* p);

class Solution {
public:
    ListNode* sortList(ListNode *head)
    {
        if ( !head || head->next == NULL)
        {
            return head;
        }

        ListNode * pA = head, *pB = head;
        while(pA && pB && pB->next && pB->next->next)
        {
            pA = pA->next;
            pB = pB->next->next;
        }
        pB = pA->next;
        pA->next = NULL;
        pA = head;
        
        pA = sortList(pA);
        pB = sortList(pB);
        return merge(pA, pB);
    };

    ListNode* merge(ListNode* pA, ListNode* pB) 
    {
        ListNode* merged;
        
        if (pA == NULL) return pB;
        if (pB == NULL) return pA;

        if ( pA->val > pB->val )
           {
               merged = pB;
               pB = pB->next;
           }
        else
        {
            merged = pA;
            pA = pA->next;
        }
        ListNode* head = merged;
         
        while( pA && pB)
        {
            if ( pA->val <= pB->val )
            {
                merged->next = pA;
                pA = pA->next;
            }
            else
            {
                merged->next = pB;
                pB = pB->next;
            }
            merged = merged->next;
        }
        if( pA != NULL  )
            merged->next = pA;
        else if ( pB != NULL )
            merged->next = pB;
        return head;
    }
};

void printList(string info, ListNode* p){
    std::cout << info; 
    while ( p != NULL )
    {
        std::cout << p->val << " ";
        p = p->next;
    }
    std::cout << std::endl;
}
int main()
{
    ListNode* head = new ListNode(6,
                        new ListNode(2,
                            new ListNode(8,
                                new ListNode(1,
                                    new ListNode(7,
                                        new ListNode(3,
                                            new ListNode(5,
                                                new ListNode(9, 
                                                    new ListNode(4,NULL)
                                                    ))))))));
    printList("init List1: ", head); 
    Solution* solver = new Solution();
    head = solver->sortList(head);
    printList("final reault1: ", head);
    ListNode* head2 = new ListNode();
    printList("init List2: ", head2);
    head2 = solver->sortList(head2);
    printList("final result2: ", head2);
    return 0;
}
