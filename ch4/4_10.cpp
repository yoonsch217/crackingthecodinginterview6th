#include <iostream>

using namespace std;

struct Node{
	Node* left = nullptr;
	Node* right = nullptr;
	int data = -1;
};


//이상한 거 같은데;;
//Time: O(n + km)
//Space: O(n+m)
bool match(const Node* t1, const Node* t2){
	if(t2 == nullptr) return true;

	if(t1 == nullptr) return false;

	if(t1->data == t2->data) return match(t1->left, t2->left) && match(t1->right, t2->right);
	else return match(t1->left, t2) || match(t1->right, t2);

}

Node* neu_node(const int& i){
	Node* n = new Node;
	n->data = i;
	return n;
}

void link(Node* n1, Node* n2, Node* n3){
	n1->left = n2;
	n1->right = n3;
}

int main(){
	auto t1 = neu_node(1);
	auto t2 = neu_node(2);
	auto t3 = neu_node(3);
	auto t4 = neu_node(4);
	auto t5 = neu_node(5);
	auto t6 = neu_node(6);
	auto t7 = neu_node(7);
	auto t8 = neu_node(8);
	auto t9 = neu_node(9);
	auto t10 = neu_node(10);

	link(t2, t3, t4);
	link(t1, t5, t6);
	link(t5, t7, t8);
	link(t6, t9, t10);
	link(t10, t2, nullptr);

	if(match(t1, t2)) cout << "True" << endl;
	else cout << "False" << endl;

	return 0;
}
