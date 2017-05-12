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

	void Graph::DFSUtil(int s, vector<bool> &visited)
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

			for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
				if (!visited[*i])
					stack.push(*i);
		}
	}
	void Graph::DFS()
	{
		vector<bool> visited(V, false);
		for (int i = 0; i < V; i++)
			if (!visited[i])
				DFSUtil(i, visited);
	}
};

int main()
{
	Graph g(5);
	g.addEdge(1, 0);
	g.addEdge(2, 1);
	g.addEdge(3, 4);
	g.addEdge(4, 0);
	g.DFS();
	return 0;
}