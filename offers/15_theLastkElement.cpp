/*
 * 输入一个链表，输出该链表中倒数第k个节点。
 *
 * 算法：前后两个指针，相隔k-1个元素同时前进。
 *
 * 例如：
 *         1 2 3 4 5 6 输出倒数第3个节点
 *
 *         1 2 3 4 5 6
 *         *   ×
 *         1 2 3 4 5 6
 *           ×   ×
 *         1 2 3 4 5 6
 *             ×   ×
 *         1 2 3 4 5 6
 *               ×   ×
 */

#include <iostream>

struct ListNode
{
	ListNode(int value, ListNode* next)
		: m_nValue(value), m_pNext(next)
	{}
	int			m_nValue;
	ListNode*	m_pNext;
};

bool getTheLastKNode(ListNode* head, int k, ListNode** retNode)
{
	if (head == NULL || k <= 0)
	{
		return false;
	}
	ListNode* pFront = head;
	ListNode* pAfter = head;
	int stepFront = k - 1;
	while (stepFront-- != 0)
	{
		if (pFront->m_pNext == NULL)
		{
			return false;
		}
		pFront = pFront->m_pNext;
	}
	while (pFront->m_pNext != NULL)
	{
		pFront = pFront->m_pNext;
		pAfter = pAfter->m_pNext;
	}
	*retNode = pAfter;
	return true;

}

int main()
{
	ListNode* head = new ListNode(1,
						new ListNode(2,
							new ListNode(3,
								new ListNode(4,
									new ListNode(5,
										new ListNode(6,
											NULL))))));
	ListNode* retNode = NULL;
	if (getTheLastKNode(head, 0, &retNode))
	{
		std::cout << retNode->m_nValue << std::endl;
	}
	return 0;
}
