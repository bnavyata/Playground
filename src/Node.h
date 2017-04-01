#pragma once

class Node
{
public:
	~Node();
	Node(int x);

	static void insertNodeBeginning(int x);
	static void insertNodeEnd(int x);
	static void deleteNode(int x);
	static void deleteAtindex(int x);

	static Node* start;

	int value;
	Node *next;
};



