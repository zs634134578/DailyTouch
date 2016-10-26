/*
 * MinStack - 包含min指针的stack，min指针指向栈中的最小元素
 * 算法：辅助栈
 *       每压入一个元素，都把该元素和当前栈的最小元素做比较
 *       将较小的数字压入辅助栈
 *       所以辅助栈的深度和数据栈相同
 */


#include <iostream>
#include <vector>
#include <assert.h>

class  MinStack
{
public:
	MinStack() {};

	void push(int x);
	void pop();
	int top();
	int getMin();

private:
	std::vector<int> dataStack;
	std::vector<int> minStack;;
};

void MinStack::push(int x)
{
	if (dataStack.size() == 0)
	{
		minStack.push_back(x);
	}
	else
	{
		int curMinElement = getMin();
		int newMinElement = x < curMinElement ? x : curMinElement;
		minStack.push_back(newMinElement);
	}
	dataStack.push_back(x);
}

void MinStack::pop()
{
	assert(dataStack.size() > 0);
	dataStack.pop_back();
	minStack.pop_back();
}

int MinStack::top()
{
	assert(dataStack.size() > 0);
	return *(dataStack.end() - 1);
}

int MinStack::getMin()
{
	assert(dataStack.size() > 0);
	return *(minStack.end() - 1);
}

int main()
{
	MinStack* minStack = new MinStack();
	// push 1
	minStack->push(1);
	std::cout << minStack->getMin() << std::endl;
	// push 2
	minStack->push(2);
	std::cout << minStack->getMin() << std::endl;
	// push -1
	minStack->push(-1);
	std::cout << minStack->getMin() << std::endl;
	// pop
	minStack->pop();
	std::cout << minStack->getMin() << std::endl;

	std::cout << minStack->top() << std::endl;
	
	return 0;
}
