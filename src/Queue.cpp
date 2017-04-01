#include "Queue.h"



Queue::Queue()
{
	mFront = 0;
	mRear = -1;
}


Queue::~Queue()
{
}

void Queue::Add(int x)
{
	mQueueElements.push_back(x);
	mRear++;
}

void Queue::Remove()
{
	if (mRear < mFront)
		return;
	else
		mFront++;
}

bool Queue::isEmpty()
{
	if (mRear < mFront)
		return true;
	return false;
}

int Queue::Peek()
{
	if (mRear >= mFront)
		return mQueueElements[mFront];
	return -1;
}