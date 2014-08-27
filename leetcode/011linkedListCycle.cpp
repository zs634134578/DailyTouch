/*问题描述：
 *    Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 *
 *    Follow up:
 *        Can you solve it without using extra space?
 */


#include <iostream>
using namespace std;

#define debug(x) std::cout << "debug: " << x << std::endl;

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
