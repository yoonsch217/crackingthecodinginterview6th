#include <iostream>
#include <unordered_map>
#include <set>


using namespace std;

class Node{
	public:
		int data;
		Node* next;
};


void insert(Node *& head, int data){
	Node * newNode = new Node;
	newNode->data = data;
	newNode->next = head;
	head = newNode;
}

void printList(Node * head){
	while(head){
		cout << head->data << "-->";
		head = head->next;
	}
	cout<< "nullptr" << endl;
}

//using buffer
//Time O(n), Space O(n)
//my code
void removeDuplicate(Node* n){

	if(n == nullptr || (n && (n->next == nullptr))) return;

	set<int> s;
	s.insert(n->data);

	Node* curr = n;

	while(curr->next != nullptr){
		if(s.find((curr->next)->data) != s.end()) {
			curr->next = (curr->next)->next;
//			cout << "found!!" << endl;
//			printList(n);
//			cout << "current is: " << curr->data << endl << endl;
		}
		else {
			s.insert((curr->next)->data);
//			cout << "not found!! insert new to set" << endl;
//			printList(n);
//			cout << "current is: " << curr->data << endl << endl;
		}

		if(curr->next == nullptr) break;
		curr = curr->next;
	}
}


//using buffer
//github solution
void removeDuplicate2(Node * n){
	if(n == nullptr || (n && n->next == nullptr)) return;

	set<int> s;
	Node* prev = n;
	Node* curr = n->next;
	s.insert(n->data);

	while(curr != nullptr){
		while(curr && s.find(curr->data) != s.end()) curr = curr->next;
		prev->next = curr;
		prev = curr;
		if(curr) {
			s.insert(curr->data);
			curr = curr->next;
		}
	}
}

//not using buffer
//my code
void removeDuplicate3(Node * n){
	if(n == nullptr || (n && (n->next == nullptr))) return;

	Node* curr = n;
	Node* check = curr;

	while(curr->next != nullptr){
	while(check->next != nullptr){
		if(curr->data == (check->next)->data){
			check->next = (check->next)->next;
		}
		else check = check->next;

	}
	curr = curr->next;
	check = curr;
	}

}

int main(){
	cout << "1" << endl;
	Node * head = nullptr;

	insert(head, 2);
	insert(head, 4);
	insert(head, 2);
	insert(head, 9);
	insert(head, 7);
	insert(head, 8);
	insert(head, 2);
	insert(head, 8);

	printList(head);
	removeDuplicate3(head);
	printList(head);

	return 0;
}
