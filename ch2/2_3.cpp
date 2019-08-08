#include <iostream>

using namespace std;

struct Node{
	int data;
	Node* next;
	Node(int d){
		data = d;
	}
};

void printList(Node* head){
	while(head){
		cout << head->data << "-->";
		head = head->next;
	}
	cout << "nullptr" << endl;
}

//github solution
void deleteNode( Node * node ) {
  if ( node == nullptr || node->next == nullptr ) {
    return;
  }
  Node * nextNode = node->next;
  node->data = nextNode->data;
  node->next = nextNode->next;
  delete nextNode;
}



//just changing the data and next node
void deleteMiddle(Node * n){
	if(n == nullptr || n->next == nullptr) {
		cout << "nullptr" << endl;
		return;
	}


	Node* temp = n;
	cout << "temp's data" << temp->data << endl;
//	n->data = temp->next->data;
	n->data = n->next->data;

	cout << "temp's data" << temp->data << endl;
//	n->next = temp->next->next;
	n->next = n->next->next;

}


int main() {
  Node * head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  head->next->next->next->next = new Node(5);
  std::cout << "List before deletion:\n";
  printList(head);
  std::cout << "Deleting node containing data as 'c'\n";
  deleteMiddle(head->next->next);
  std::cout << "List after deletion:\n";
  printList(head);
  return 0;
}
