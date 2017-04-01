#include "Stack.h"
#include <iostream>

Stack::Stack()
{
	mTop = -1;
}


Stack::~Stack()
{
}

void Stack::Push(int x)
{
	mStackElements.push_back(x);
	mTop++;
}

void Stack::Pop()
{
	std::cout << "Popping value " <<mStackElements[mTop] << std::endl;
	if (!isEmpty())
		mTop--;
	else
		return;
}

bool Stack::isEmpty()
{
	if (mTop == -1)
		return true;
	return false;
}

int Stack::Peek()
{
	if(mTop!=-1)
		return mStackElements[mTop];
	return -1;
}
