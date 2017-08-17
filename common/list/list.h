
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
    char* ToString()
    {
        // mem leak
        char* str = new char[32];
        int n = sprintf(str, "%d", val);
        return str;
    }
};

struct RandomListNode
{
    int label;
    RandomListNode *next, *random;
    RandomListNode(int _label) 
        : label(_label), next(NULL), random(NULL)
    {}
    RandomListNode(int _label, RandomListNode* _next)
        : label(_label), next(_next), random(NULL)
    {}
    RandomListNode(int _label, RandomListNode* _next,
            RandomListNode* _random)
        : label(_label), next(_next), random(_random)
    {}
    void SetNext(RandomListNode* _next)
    {
        next = _next;
    }
    void SetRandom(RandomListNode* target)
    {
        random = target;
    }
    std::string ToString()
    {
        char str[32];
        int n = sprintf(str, "%d", label);
        // copy
        return str;
    }
};

template<class T>
void PrintList(T* node)
{
    while (node != NULL)
    {
        std::cout << node->ToString();
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
