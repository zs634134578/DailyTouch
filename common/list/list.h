
template<typename T>
struct Node 
{
    T val;
    Node *next;
    Node(T x) : val(x), next(NULL) {}
    Node(T x, Node* _next) : val(x), next(_next) {}
};

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    // may mem leak. be careful.
    ListNode(int x, ListNode* _next) : val(x), next(_next) {}
};

void PrintList(ListNode* node)
{
    while (node != NULL)
    {
        std::cout << node->val;
        if (node->next != NULL)
        {
            std::cout << " ";
        }
        else
        {
            std::cout << std::endl;
        }
        node = node->next;
    }
}
