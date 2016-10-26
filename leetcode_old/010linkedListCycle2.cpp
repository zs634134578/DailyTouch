/*问题描述：
 *    Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 *
 *    Follow up:
 *        Can you solve it without using extra space?
 */


#include <iostream>
#include "common.h"
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val):val(val), next(NULL) {}
    ListNode(int val, ListNode* next) : val(val), next(next) {}
};

class Solution {
    public:
        ListNode* detectCycle(ListNode* head){
            if ( head == NULL || head->next == NULL)
                return head;
            ListNode* p1 = head, *p2 = head, *p3 = head;
            bool hasCircle = true;
            do {
                if (p1 == NULL or p2 == NULL or p2->next == NULL
                    or p2->next->next == NULL)
                {
                    hasCircle = false;
                    break;
                }
                p1 = p1->next;
                p2 = p2->next->next;
            } while( p1 != p2);
            if ( !hasCircle )
                return NULL;
            while( p1 != p3)
            {
                p1 = p1->next;
                p3 = p3->next;
            }
            return p1;
        }
};

ListNode* getList(){
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    ListNode* node6 = new ListNode(6);
    ListNode* node7 = new ListNode(7);
    ListNode* node8 = new ListNode(8);
    ListNode* node9 = new ListNode(9);
    
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;
    node8->next = node9;
    node9->next = node4;
    
    return node1;
}

void test()
{
    ListNode* root = getList();
    Solution* solver = new Solution();
    solver->detectCycle(root);
}

int main()
{
    test();
    std::cout << "Hello world!" << std::endl;
    return 0;    
}
