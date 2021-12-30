#include <iostream>

using namespace std;

class Node{
	public:
	Node* next;
	int data;
    Node(int d) : data{ d }, next{ nullptr } { }

};


void insert( Node * & head, int data ) {
  Node * newNode = new Node(data);
  newNode->next = head;
  head = newNode;
}

/**
 * [deleteList - delete the entire list]
 * @param head - head of the list
 */
void deleteList( Node * & head ) {
  Node * nextNode;
  while(head) {
    nextNode = head->next;
    delete(head);
    head = nextNode;
  }
}

/**
 * printList - Helper routine to print the list
 * @param head - Current head of the list.
 */
void printList( Node * head ) {
  while(head) {
    std::cout << head->data << "-->";
    head = head->next;
  }
  std::cout << "null" << std::endl;
}

/************************************/
//recursive
//Space O(n)
Node* kthLast(Node* head, int k, int& i){
	if(head == nullptr) return nullptr;

	Node* nd = kthLast(head->next, k, i);

	i++;

	if(i == k) return head;

	return nd;

}

Node* kthLast(Node* head, int k){
	int i = 0;
	return kthLast(head, k, i);
}



//interation

Node* kthLast2(Node* head, int k){
	if(head == nullptr) return head;

	Node* runner1 = head;
	Node* runner2 = head;

	for(int i = 0; i < k; i++){
		if(runner2->next == nullptr) cout<<"Unavailable k" << endl;
		runner2 = runner2->next;
	}

	while(runner2 != nullptr){
		runner1 = runner1->next;
		runner2 = runner2->next;
	}

	return runner1;

}
/************************************/


int main() {
  Node * head = nullptr;
  for ( int i = 7; i > 0; i-- ) {
    insert(head, i);
  }
  std::cout << "List: ";
  printList(head);

  std::cout << "4th node from last (Recursive) : ";
  Node *node4 = kthLast(head, 4);
  if ( node4 != nullptr ) {
    std::cout << node4->data << std::endl;
  } else {
    std::cout << "NULL NODE\n";
  }

  std::cout << "4th node from last (Iterative) : ";
  node4 = kthLast2(head, 4);
  if ( node4 != nullptr ) {
    std::cout << node4->data << std::endl;
  } else {
    std::cout << "NULL NODE\n";
  }

  deleteList(head);

  return 0;
}
