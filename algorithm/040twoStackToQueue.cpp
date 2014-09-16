/*
 * two stacks ----> queue
 * methods:
 *     add
 *     remove
 */

#include <iostream>
#include <stack>

using namespace std;

#define debug(x, y) std::cout << "(debug)" << x << y << std::endl;

template<class T>
class MyQueue
{
public:
    MyQueue() {}

    void add(T ele);
    void remove();
    void printAll();
private:
    stack<T> stack1;
    stack<T> stack2;
};

template<class T>
void MyQueue<T>::add(T ele)
{
    if (!this->stack2.empty())
    {
        while(!this->stack2.empty())
        {
            this->stack1.push(this->stack2.top());
            this->stack2.pop();
        }
    }
    this->stack1.push(ele);
}

template<class T>
void MyQueue<T>::remove()
{
    if (!this->stack1.empty())
    {
        while(!this->stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
        debug("remove:", stack2.top());
        stack2.pop();
    }
}

template<class T>
void MyQueue<T>::printAll()
{
    if (!this->stack2.empty())
    {
        while(!this->stack2.empty())
        {
            this->stack1.push(this->stack2.top());
            this->stack2.pop();
        }
    }
    debug("stack1 size:", this->stack1.size());
    if (!this->stack1.empty()) 
    {
        while(!this->stack1.empty())
        {
            std::cout << this->stack1.top() << std::endl;
            stack2.push(stack1.top());
            stack1.pop();
       }
    }
    
}


int main()
{
    MyQueue<int> mq;
    mq.add(1);
    mq.add(2);
    mq.remove();
    mq.printAll();
    debug("Hello world!", "");
    return 0;
}
