#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <list>
using namespace std;

class Graph {
public:
	int V;
	list<int> *adj;

	Graph(int V) {
		this->V = V;
		adj = new list<int>[V];
	}

	void addNode(int i, int j) {
		adj[i].push_back(j);
	}

	bool isCyclicUtil(int i, bool *visited, bool *recStack) {
		if (visited[i] == false) {
			visited[i] = true;
			recStack[i] = true;
			for (auto it = adj[i].begin(); it != adj[i].end(); it++) {
				if (!visited[*it] && isCyclicUtil(*it, visited, recStack))
					return true;
				else if (recStack[*it])
					return true;
			}
		}
		return false;
	}

	bool Graph::isCyclic() {
		bool * visited = new bool[V];
		bool * recStack = new bool[V];

		for (int i = 0; i < V; i++) {
			visited[i] = false;
			recStack[i] = false;
		}

		for (int i = 0; i < V; i++) {
			if (isCyclicUtil(i, visited, recStack))
				return true;
		}
		return false;
	}
};

int main()
{
	Graph myGraph(4);
	myGraph.addNode(0, 1);
	myGraph.addNode(0, 2);
	myGraph.addNode(1, 2);
	myGraph.addNode(2, 0);
	myGraph.addNode(2, 3);
	myGraph.addNode(3, 3);
	bool result = myGraph.isCyclic();
	cout << result << endl;
	return 0;
}