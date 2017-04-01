#include "Node.h"
#include <iostream>

Node* Node::start = NULL;

Node::~Node()
{
}


Node::Node(int x) {
	this->value = x;
	this->next = NULL;
}


void Node::insertNodeBeginning(int x)
{
	Node *a = new Node(x);

	if (start == NULL)
		start = a;
	else
	{
		a->next = start;
		start = a;
	}

}

void Node::insertNodeEnd(int x)
{
	Node *a = new Node(x);
	if (start == NULL)
		start = a;
	else
	{
		Node *temp;
		temp = start;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = a;
	}
}

void Node::deleteNode(int x)
{
	Node *temp = start;
	if (temp->value == x)
	{
		start = temp->next;
		delete temp;
		return;
	}
	while (temp->next != NULL)
	{
		if (temp->next->value == x)
		{
			Node *rem = temp->next;
			temp->next = temp->next->next;
			delete rem;
			break;
		}
		temp = temp->next;
	}
}

void Node::deleteAtindex(int x)
{
	int i;
	Node *temp = start;
	for (i = 0; i < x - 1; i++)
	{
		if (temp == NULL)
			break;
		temp = temp->next;
	}
	if (i == x - 2)
	{
		if ((temp != NULL) && (temp->next != NULL))
		{
			Node *del = temp->next;
			temp->next = temp->next->next;
			delete del;
		}
	}
}