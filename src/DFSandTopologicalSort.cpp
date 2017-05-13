#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
using namespace std;

class Graph {
	int V;
	list<int> *adj;
public:
	Graph(int V) {
		this->V = V;
		adj = new list<int>[V];
	}

	void addEdge(int i, int j) {
		adj[i].push_back(j);
	}
// DFS iterative using stack
	void DFSUtil(int s, vector<bool> &visited)
	{
		stack<int> stack;
		stack.push(s);
		while (!stack.empty())
		{
			s = stack.top();
			stack.pop();
			if (!visited[s])
			{
				cout << s << " ";
				visited[s] = true;
			}

			for (auto i = adj[s].begin(); i != adj[s].end(); ++i) {
				if (!visited[*i])
					stack.push(*i);
			}	
		}
	}
// DFS recursive 
	void DFSUtilRecursive(int s, vector<bool> &visited) {
		if (!visited[s]) {
			cout << s << " ";
			visited[s] = true;
		}
		for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
			if (!visited[*i])
				DFSUtil(*i, visited);
	}

	void DFS()
	{
		vector<bool> visited(V, false);
		for (int i = 0; i < V; i++)
			if (!visited[i])
				DFSUtilRecursive(i, visited);
	}
// topological sort using recursion and stack
	void topologicalSortUtil(int i, bool visited[],stack<int> &Stack)
	{
		visited[i] = true;
		for (auto it = adj[i].begin(); it != adj[i].end(); ++it){
			if (!visited[*it])
				topologicalSortUtil(*it, visited, Stack);
		}
		Stack.push(i);
	}

	void topologicalSort()
	{
		stack<int> Stack;
		bool *visited = new bool[V];
		for (int i = 0; i < V; i++)
			visited[i] = false;

		for (int i = 0; i < V; i++) {
			if (!visited[i])
				topologicalSortUtil(i, visited, Stack);
		}
		while (!Stack.empty())
		{
			cout << Stack.top() << " ";
			Stack.pop();
		}
	}
};

int main()
{
	Graph g(6);
	g.addEdge(5, 2);
	g.addEdge(5, 0);
	g.addEdge(4, 0);
	g.addEdge(4, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 1);
	g.DFS();
	return 0;
}