#include <iostream>

using namespace std;

struct Node{
	int data;
	Node* next;
	Node(int d){
		data = d;
		next = nullptr;
	}
};






//partitioning
//my code
Node* partition(Node* head, int x){
	if(head == nullptr || head->next == nullptr) return nullptr;

	Node* curr = head;

	while(curr->next != nullptr){
		if (curr->next->data < x){
			Node* temp = curr->next;
			curr->next = curr->next->next;
			temp->next = head;
			head = temp;
		}

		else {
			curr = curr->next;
		}
	}

	return head;

}

//github solution
Node* partition2(Node* listhead, int x){
	Node* head = nullptr;
	Node* headInitial = nullptr;
	Node* tail = nullptr;
	Node* tailInitial = nullptr;
	Node* curr = listhead;

	while(curr != nullptr){
		Node* nextNode = curr->next;
		if(curr->data < x){
			if(head == nullptr){
				head = curr;
				headInitial = head;
			}
			head->next = curr;
			head = curr;
		}else{
			if(tail == nullptr){
				tail = curr;
				tailInitial = tail;

			}
			tail->next = curr;
			tail = curr;
		}
		curr = nextNode;
	}
	head->next = tailInitial;
	tail->next = nullptr;
	return headInitial;
}


/////////////////////////////////////////////////////
void insert(Node *& head, int data){
	Node* newNode = new Node(data);
	if(head == nullptr) head = newNode;
	else{
		Node* curr = head;
		while(curr->next) curr = curr->next;
		curr->next = newNode;
	}
}

void printList(Node* head){
	while(head){
		cout << head->data << "-->";
		head = head->next;
	}
	cout << "nullptr" << endl;
}


int main(){
	Node* head = nullptr;
	insert(head, 6);
	insert(head, 7);
	insert(head, 6);
	insert(head, 1);
	insert(head, 2);
	insert(head, 3);
	insert(head, 1);


	cout << "List before partition 5  ";
	printList(head);
	cout << "List after  ";
	printList(partition2(head,5));

	return 0;
}
