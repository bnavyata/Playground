#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <vector>
using namespace std;

stack<int> myStack;
stack<int> myMinStack;

void push(int x) {
	if ((myStack.empty())||(x<myStack.top()))
		myStack.push(x);
	else {
		while ((!myStack.empty())&&(x>myStack.top())){
			myMinStack.push(myStack.top());
			myStack.pop();
		}
		myMinStack.push(x);
		while (!myMinStack.empty()) {
			myStack.push(myMinStack.top());
			myMinStack.pop();
		}
	}
}

void pop() {
	myStack.pop();
}

int peek() {
	return myStack.top();
}

bool isEmpty() {
	return myStack.empty();
}

int main() {
	push(1);
	push(3);
	push(4);
	push(2);

	return 0;
}