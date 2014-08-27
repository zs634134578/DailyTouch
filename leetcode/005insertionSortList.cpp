#include <iostream>
using namespace std;

#define debug(x,y) std::cout << x << ": " << y  << std::endl;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void printList(string info, ListNode* p);

class Solution {
public:
    ListNode* insertionSortList(ListNode *head)
    {
        if( head == NULL || head->next == NULL )
            return head;

        ListNode *left,*preleft, *preright, *right;
        left = preright = head;
        preleft = NULL;
        right = head->next;
        while( right != NULL)
        {
            while( left != right && left->val <= right->val )
            {
                preleft = left;
                left = left->next;
            }
            
            if ( left == right )
            {
                preright = right;
                right = right->next;
                left = head;
                preleft = NULL;
                continue;
            }

            else
            {
                preright->next = right->next;
                right->next = left;
                if( preleft != NULL )
                    preleft->next = right;
                else
                    head = right;
                right = preright->next;
                left = head;
                preleft = NULL;
            }
        }
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
 
    Solution * solver = new Solution();
    head = solver->insertionSortList(head);
    printList("final result: ", head);
    std::cout << "Hello wrold" << std::endl;
    return 0;
}
