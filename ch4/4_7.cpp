//github.com/impo/ctci/blob/...

//Implementation with DFS NEEDED!!

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

struct Node{
	string name;
	vector<Node*> outgoing;
	vector<Node*> incoming;
};

struct Graph{
	vector<Node*> vertices;
	size_t edge_count = 0;
};

map<string, Node*> construct_nodes(){
	map<string, Node*> m;
	cout << "projects: " << endl;

	string s;
	getline(cin, s);
	//cin >> s;

	stringstream ss(s);
	string project;
	while(getline(ss, project, ' ')){
		Node* n = new Node;
		n->name = project;
		m[project] = n;
	}
	return m;
}

size_t construct_neighbors(map<string, Node*>& m){
	size_t edge_count = 0;
	cout << "dependencies:" << endl;
	string f, s;
	getline(cin, s);

	stringstream ss(s);
	while(ss >> f >> s){
		m[f]->outgoing.push_back(m[s]);
		m[s]->incoming.push_back(m[f]);
		++edge_count;
	}
	return edge_count;
}

Graph construct_graph(){
	Graph g;

	map<string, Node*> m = construct_nodes();
	g.edge_count = construct_neighbors(m);

	for(auto const &p : m) g.vertices.push_back(p.second);

	return g;
}

bool create_build(Graph& g, vector<Node*>& b){
	vector<Node*> no_incoming;
	for(Node* n : g.vertices){
		if(n->incoming.empty()) no_incoming.push_back(n);
	}
	while(!no_incoming.empty()){
		b.push_back(no_incoming.back());
		no_incoming.pop_back();
		for(Node* m : (b.back()->outgoing)){
			m->incoming.erase(
					remove(m->incoming.begin(), m->incoming.end(), b.back())
					, m->incoming.end()
					);
			--g.edge_count;
			if(m->incoming.empty()) no_incoming.push_back(m);
		}
	}
	return (g.edge_count == 0);
}

void print_build(const vector<Node*>& b){
	for (auto const &n : b) cout << n->name << " ";
	cout << endl;
}

int main(){
	Graph g = construct_graph();
	vector<Node*> build;
	if(create_build(g,build)) print_build(build);
	else cout << "Fail" << endl;

	return 0;
}
