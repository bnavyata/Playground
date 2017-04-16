#include <iostream>
#include <stack>
#include <string>
#include <set>
#include <memory>
#include <vector>
#include <utility>
#include <map>
using namespace std;

struct Node {
	Node(string name) {
		value = name;
		visited = false;
	}
	bool visited;
	string value;
	vector<Node*> adjList;
};

map<string,Node*> buildGraph(const vector<pair<string, string>>& rel) {
	
	map<string, Node*> Graph;
	for (auto itr = rel.begin(); itr != rel.end(); itr++) {
		Node* dep = NULL;
		Node* parentDep = NULL;
		string depName = (*itr).first;
		if (Graph.find(depName) == Graph.end()) {
			dep = new Node(depName);
			Graph.insert(make_pair(depName, dep));
		}
		else {
			dep = Graph.find(depName)->second;
		}
		if (Graph.find((*itr).second) == Graph.end()) {
			parentDep = new Node((*itr).second);
			Graph.insert(make_pair((*itr).second, parentDep));
		}
		else {
			parentDep = Graph.find((*itr).second)->second;
		}
		dep->adjList.push_back(parentDep);

	}
	return Graph;
}

void topologicalSort(Node* root, vector<string> &stk) {
	root->visited = true;

	for (auto i = root->adjList.begin(); i != root->adjList.end(); i++) {
		if (!(*i)->visited) {
			topologicalSort(*i, stk);
		}
	}

	stk.push_back(root->value);
}

shared_ptr<vector<string>> serialize_build_order(const vector<pair<string,string>>& relations) {
	map<string, Node*> Graph = buildGraph(relations);
	shared_ptr<vector<string>> res (new vector<string>);
	for (auto itr = Graph.begin(); itr != Graph.end(); itr++) {
		if ((*itr).second->visited == false) {
			topologicalSort((*itr).second, *res);
		}
	}
	return res;
}



int main() {
	vector<pair<string, string>> deps;
	deps.push_back(make_pair<string, string>("numpy", "python"));
	deps.push_back(make_pair<string, string>("scipy", "python"));
	deps.push_back(make_pair<string, string>("matplotlib", "python"));
	deps.push_back(make_pair<string, string>("matplotlib", "numpy"));
	deps.push_back(make_pair<string, string>("imageio", "numpy"));
	deps.push_back(make_pair<string, string>("python", "ubuntu"));

	shared_ptr<vector<string>> pRes = serialize_build_order(deps);
	for (int i = 0; i < (*pRes).size(); i++) {
		cout << (*pRes)[i] << endl;
	}
}

