#pragma once
#include "Stack.h"
#include <vector>

class MinStack:public Stack
{
public:
	MinStack();
	~MinStack();
	int Min();
	void Push(int x);
	void Pop();

	std::vector<int> mMinList;
};

