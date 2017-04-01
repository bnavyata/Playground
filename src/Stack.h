#pragma once
#include<vector>

class Stack
{
public:
	Stack();
	~Stack();
	virtual void Push(int x);
	virtual void Pop();
	bool isEmpty();
	int Peek();

protected:
	std::vector<int> mStackElements;
	int mTop;
};

