#include <iostream>

using namespace std;

struct Node {
  int data;
  Node * next;
  Node ( int d ) : data{ d }, next{ nullptr } { }
};


//github solution

Node* add_iterative(Node* list1, Node* list2){
	if(list1 == nullptr) return list2;
	if(list2 == nullptr) return list1;

	Node* list3 = nullptr;
	Node* list3Tail = nullptr;

	int value=0, carry=0;

	while(list1 || list2){
		value = carry + (list1 ? list1->data : 0) + (list2 ? list2->data : 0);

		if(value > 9){
			carry = 1;
			value = value % 10;
		}else carry = 0;

		Node* temp = new Node(value);

		if(list3 == nullptr) list3 = temp;
		else list3Tail->next = temp;

		list3Tail = temp;

		if(list1) list1 = list1->next;
		if(list2) list2 = list2->next;

		if(carry>0) list3Tail->next = new Node(carry);

		return list3;
	}
}


//github solution
//recursive
Node* add_recursive(Node* list1, Node* list2, int carry){
	if(list1 == nullptr && list2 == nullptr && carry == 0) return nullptr;

	int value = carry;

	if(list1) value += list1->data;
	if(list2) value += list2->data;

	Node* resultNode = new Node(value%10);
	resultNode->next = add_recursive(list1 ? (list1->next) : nullptr, list2 ? (list2->next) : nullptr, value > 9 ? 1 : 0);

	return resultNode;
}










/**
 * [insert - insert a new node at head of the list]
 * @param head [head of the list]
 * @param data [new node's data]
 */
void insert( Node * & head, int data ) {
  Node * newNode = new Node(data);
  newNode->next = head;
  head = newNode;
}

/**
 * [printList - print the list]
 * @param head [head of the list]
 */
void printList( Node * head ) {
  while ( head ) {
    std::cout << head->data << "-->";
    head = head->next;
  }
  std::cout << "nullptr" << std::endl;
}


 void deleteList( Node * & head ) {
   Node * nextNode;
   while(head) {
     nextNode = head->next;
     delete(head);
     head = nextNode;
   }
 }



int main()
{
  //making list 1 for number 617
  Node * list1 = nullptr;
  insert(list1, 6);
  insert(list1, 1);
  insert(list1, 7);
  std::cout << "List1:  ";
  printList(list1);

  //making list2 for number 295
  Node * list2 = nullptr;
  insert(list2, 2);
  insert(list2, 9);
  insert(list2, 5);
  std::cout << "List2:  ";
  printList(list2);

  Node * list3 = add_iterative(list1, list2);
  std::cout << "Iterative Solution: \n";
  std::cout << "List3:  ";
  printList(list3);

  Node * list4= add_recursive(list1, list2, 0);
  std::cout << "Recursive Solution: \n";
  std::cout << "List4:  ";
  printList(list4);

  deleteList(list1);
  deleteList(list2);
  deleteList(list3);
  deleteList(list4);

  /*
  std::cout << "\n\nNow follow up case, lists are stored such that 1's digit is at the tail of list\n";
  //Node * listx = nullptr;
  insert(list1, 4);
  insert(list1, 3);
  insert(list1, 2);
  insert(list1, 9);
  std::cout << "List1:  ";
  printList(list1);

  insert(list2, 9);
  insert(list2, 9);
  insert(list2, 8);
  std::cout << "List2:  ";
  printList(list2);

  list3 = add_followup(list1, list2);
  std::cout << "Adding two above lists\n";
  std::cout << "List3:  ";
  printList(list3);

  deleteList(list1);
  deleteList(list2);
  deleteList(list3);
*/
  return 0;
}
