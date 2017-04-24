#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class graphNode {
public:
	int val;
	vector<graphNode *> adjList;
	bool visited;
	//constructor
	graphNode(int val) {
		this->val = val;
		this->visited = false;
	}
};

//DFS
bool DFS_util(graphNode* node, int target) {
	if (!node->visited) {
		(node)->visited = true;
		if (node->val == target)
			return true;
		else {
			for (auto it = node->adjList.begin(); it != node->adjList.end(); it++) {
				if (DFS_util(*it, target))
					return true;
			}
		}
	}
	return false;
}

bool DFS(vector<graphNode*> Graph, int target) {
	for (auto it = Graph.begin(); it != Graph.end(); it++){
		if (DFS_util(*it, target))
			return true;
	}
	return false;
}

//BFS 
bool BFS_util(graphNode* node, int target) {
	queue<graphNode*> myQueue;
	myQueue.push(node);
	int temp;
	while (!myQueue.empty()) {
		temp = myQueue.front()->val;
		if (temp == target) return true;
		myQueue.pop();
		for (auto it = node->adjList.begin(); it != node->adjList.end(); it++) {
			if (!(node->visited = true)) {
				node->visited = true;
				myQueue.push(*it);
			}
		}
	}
	return false;
}
bool BFS(vector<graphNode*> Graph, int target) {
	for (auto it = Graph.begin(); it != Graph.end(); it++) {
		if (BFS_util(*it, target))
			return true;
	}
	return false;
}


int main()
{
	bool resultDFS, resultBFS;
	int target = 3;
	vector<graphNode*> Graph;
	graphNode* one = new graphNode(1);
	Graph.push_back(one);
	graphNode* two = new graphNode(2);
	Graph.push_back(two);
	graphNode* three = new graphNode(3);
	Graph.push_back(three);
	graphNode* four = new graphNode(4);
	Graph.push_back(four);
	graphNode* five = new graphNode(5);
	Graph.push_back(five);
	graphNode* six = new graphNode(6);

	one->adjList.push_back(two);
	one->adjList.push_back(three);
	two->adjList.push_back(four);
	two->adjList.push_back(five);
	three->adjList.push_back(six);

	resultDFS = DFS(Graph, target);
	resultBFS = BFS(Graph, target);
	cout << "result of DFS: " << resultDFS << endl;
	cout << "result of BFS: " << resultBFS << endl;
	return 0;
}
