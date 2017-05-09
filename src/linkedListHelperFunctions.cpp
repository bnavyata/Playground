#include <iostream>
using namespace std;

struct Node {
	int val;
	Node* next;

	Node(int x) {
		val = x;
		next = NULL;
	}
};

Node* deleteMiddle(Node* head) {
	Node* pre = NULL;
	Node* slow = head;
	Node* fast = head;
	if (!head) return NULL;
	if (!head->next) {
		delete head;
		return NULL;
	}
	while (fast && (fast->next)) {
		pre = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	pre->next = slow->next;
	delete slow;
	return head;
}

Node* removeDuplicates(Node* head) {
	if (!head) return NULL;
	Node* current = head;
	while (current->next) {
		if (current->val != current->next->val) {
			current = current->next;
		}
		else {
			Node* temp = current->next;
			current->next = current->next->next;
			delete temp;

		}
	}
	return head;
}

Node* reverseList(Node* head) {
	if (!head||!head->next) return head;
	Node* node = reverseList(head->next);
	head->next->next = head;
	head->next = NULL;
	return node;
}

Node* addOneIterative(Node* head) {
	Node *temp = reverseList(head);
	int carry = 0;
	Node* headCopy = temp;
	headCopy->val += 1;
	while (headCopy) {	
		headCopy->val += carry;
		if (headCopy->val / 10 == 1) {
			carry = 1;
			headCopy->val %= 10;
		}
		else
			carry = 0;
		if (carry&&(!(headCopy->next)))
		{
			Node* node = new Node(1);
			headCopy->next = node;
			carry = 0;
		}
		headCopy = headCopy->next;
	}
	
	return reverseList(temp);
}

void addOne_Util(Node* head, int &carry) {
	if (!head)
		return;
	//end condition
	if (!head->next) {
		head->val += 1;
		carry = (head->val) / 10;
		head->val %= 10;
		return;
	}
	//recursive call
	addOne_Util(head->next, carry);
	head->val += carry;
	carry = (head->val) / 10;
	head->val %= 10;
}

Node* addOneRecursive(Node* headPtr) {
	int carry = 0;
	addOne_Util((headPtr), carry);
	if (carry == 1) {
		Node* newNode = new Node(1);
		newNode->next = headPtr;
		headPtr = newNode;
	}
	return headPtr;
}

Node *detectCycleMine(Node *head) {
	Node *slow = head;
	Node *fast = head;

	while (fast && fast->next)
	{
		
		
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			break;
	}

	if (slow == fast)
	{
		slow = head;
		while (slow != fast)
		{
			slow = slow->next;
			fast = fast->next;
		}

		return fast;
	}
}
Node *detectCycle(Node *head) {
	if (head == NULL || head->next == NULL) return NULL;

	Node* firstp = head;
	Node* secondp = head;
	bool isCycle = false;

	while (firstp != NULL && secondp != NULL) {
		firstp = firstp->next;
		if (secondp->next == NULL) return NULL;
		secondp = secondp->next->next;
		if (firstp == secondp) { isCycle = true; break; }
	}

	if (!isCycle) return NULL;
	firstp = head;
	while (firstp != secondp) {
		firstp = firstp->next;
		secondp = secondp->next;
	}

	return firstp;
}

int main() {

	Node* head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(5);
	head->next->next->next->next->next = head->next->next;
	cout << detectCycleMine(head)->val;
	return 0;
}