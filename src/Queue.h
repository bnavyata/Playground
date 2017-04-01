#pragma once
#include <vector>
class Queue
{
public:
	Queue();
	~Queue();
	void Add(int x);
	void Remove();
	bool isEmpty();
	int Peek();

private:
	std::vector<int> mQueueElements;
	int mFront;
	int mRear;
};

