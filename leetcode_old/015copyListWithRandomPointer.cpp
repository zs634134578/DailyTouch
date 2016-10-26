/*
 * Definition for singly-linked list with a random pointer.
 *  * struct RandomListNode {
 *  *     int label;
 *  *     RandomListNode *next, *random;
 *  *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 *  * };
 *
 * !!!!!Online Judge Failed.
 */

#include "common.h"
#include <map>

using namespace std;

#define debug(x, y) std::cout << "(debug)" << x << y << std::endl;
#define print(x) std::cout << x << std::endl;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
    RandomListNode(int x, RandomListNode* n):
        label(x), next(n), random(NULL) {}
};


class Solution
{
public:

    RandomListNode* copyRandomList(RandomListNode * head)
    {
        return copyRandomList2(head);
    }

    /* origin list: a1->b1->c1->d1->e1->NULL
     * step1: copy each node and insert to its next position 
     *          a1->a2-b1->b2->c1->c2->d1->d2->e1->e2->NULL
     * step2: set random pointer to right nodes
     * step3: set next pointer to right nodes
     */
    RandomListNode* copyRandomList2(RandomListNode * head)
    {
        if ( head == NULL) return head;

        RandomListNode* curNode, *newHead,*copyNode, *curNewNode;
        curNode = head;
        copyNode = NULL;
        newHead = NULL;
        while ( curNode )
        {
            copyNode = new RandomListNode(curNode->label);
            if (!newHead)
                newHead = copyNode;
            copyNode->next = curNode->next;
            curNode->next = copyNode;
            curNode = curNode->next->next;
        }
        //debug("after insert copy node", "");
        //printList(head);
        
        // copy random pointer
        curNode = head;
        curNewNode = newHead;
        while( curNode )
        {
            if ( curNode->random == NULL)
                curNewNode->random = NULL;
            else 
                curNewNode->random = curNode->random->next;
            curNode = curNode->next->next;
        }
        //debug("after copy random pointer", "");
        //printList(head);
        
        // copy next pointer
        curNode = head;
        curNewNode = newHead;
        
        while ( curNewNode )
        {
            /*
            if ( curNewNode->next == NULL)
            {
                curNode->next = NULL;
                break;
            }
            */
            curNode->next = curNewNode->next;
            curNode = curNode->next;
            if (curNode == NULL)
                break;
            curNewNode->next = curNode->next;
            curNewNode = curNewNode->next;
        }
        //debug("after copy next pointer", "");
        //printList(newHead);
        //printList(head);
        return newHead;
    }



    RandomListNode* copyRandomList1(RandomListNode *head)
    {
        map<RandomListNode*,RandomListNode*> rrmap;
        RandomListNode* p = head;
        while(p != NULL) 
        {
            if ( rrmap.find(p) == rrmap.end())
            {
                RandomListNode* tmpNode = new RandomListNode(p->label);
                rrmap[p] = tmpNode;
            }
            p = p->next;
        }
        for ( map<RandomListNode*, RandomListNode*>::iterator it = rrmap.begin(); it != rrmap.end(); it++) 
        {
            it->second->next = rrmap[it->first->next];
            it->second->random = rrmap[it->second->random];
        }
        debug("newHead:", rrmap[head]->label);
        return rrmap[head];
    }

};


RandomListNode* createList()
{
    // case 3
    RandomListNode* node1 = new RandomListNode(1);
    RandomListNode* node2 = new RandomListNode(2);
    RandomListNode* node3 = new RandomListNode(2);
    RandomListNode* node4 = new RandomListNode(2);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    node1->random = node3;
    node2->random = node4;
    node3->random = node1;
    
    /*
    // case 2
    RandomListNode* node1 = new RandomListNode(-1);
    RandomListNode* node2 = new RandomListNode(-1);
    node1->next = node2;
    node1->random = NULL;
    */
    
    /*
    node1->next = NULL;
    node1->random = NULL;
    */
    /*
    // case 1
    RandomListNode* node2 = new RandomListNode(2);
    RandomListNode* node3 = new RandomListNode(3);
    RandomListNode* node4 = new RandomListNode(4); 
    RandomListNode* node5 = new RandomListNode(5); 
    RandomListNode* node6 = new RandomListNode(6); 

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;

    node1->random = node4;
    node2->random = node1;
    node3->random = NULL;
    node4->random = node2;
    node5->random = node2;
    node6->random = node3;
    */

    return node1;

}

int main()
{
    Solution* solver = new Solution();
    RandomListNode* head = createList();
    RandomListNode* newHead = solver->copyRandomList(head);
    printList(newHead);
    print("Hello world!");
    return 0;
}
