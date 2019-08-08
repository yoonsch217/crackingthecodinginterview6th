#include <cstdlib>
using namespace std;


struct Node{
	Node* left = nullptr;
	Node* right = nullptr;
	Node* parent = nullptr;
};

size_t find_depth(Node* n){
	size_t depth = 0;
	while(n = n->parent) ++depth;
	return depth;
}

Node* common_ancestor(Node* n1, Node* n2){
	size_t h1 = find_depth(n1);
	size_t h2 = find_depth(n2);

	while(h1>h2){
		n1 = n1->parent;
		--h1;
	}
	while(h2>h1){
		n2 = n2->parent;
		--h2;
	}

	while(n1 != n2){
		n1 = n1->parent;
		n2 = n2->parent;
	}

	return n1;
}
//O(d) when d is the depth of the deeper node

int main(){


	return 0;
}
