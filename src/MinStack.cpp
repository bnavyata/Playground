#include "MinStack.h"
#include <iostream>
using namespace std;

MinStack::MinStack()
{
	
}


MinStack::~MinStack()
{
}

int MinStack::Min()
{
	if(!isEmpty())
		return mMinList.back();
	return - 1;
}

void MinStack::Push(int x) 
{
	if (isEmpty())
		mMinList.push_back(x);
	else
	{
		if (x <= mMinList.back())
			mMinList.push_back(x);
	}
	mStackElements.push_back(x);
	cout << "Inserted value: " << x << endl;
	mTop++;
}

void MinStack::Pop()
{
	if (mStackElements[mTop] == mMinList.back())
		mMinList.pop_back();

	if (!isEmpty())
			mTop--;
	else
		return;

}


