#include <iostream>
//#include "myStack.hpp"

using namespace std;


struct Node{
	Node* next;
	int data;

	Node(int v){data = v;}
	Node(int v, Node* n) : data(v), next(n){}
};

class Stack{
	public:
		Stack() : top(nullptr), stackSize(0){}
		~Stack(){
			while(!isEmpty()) pop();
		}

		int pop(){
			if(isEmpty()) return -217;

			int rtn = top->data;
			top = top->next;
			stackSize--;

			if(rtn == min_top->data){
				min_top = min_top->next;
			}

			return rtn;
		}

		void push(int i){
			Node* tmp = new Node(i, top);
//			tmp->next = top;
			top = tmp;
			stackSize++;

			if(min_top == nullptr || i <= min_top->data){
				Node* tmp2 = new Node(i, min_top);
				min_top = tmp2;
			}
		}

		bool isEmpty(){
			return (stackSize == 0 || top == nullptr);
		}

		int peek(){
			if(isEmpty()) return -217;
			return top->data;
		}

		int min(){
			return min_top->data;
		}

	private:
		Node* top;  //head를 top으로 본다. push할 때 head에 추가. head를 바꿔야되네.
		int stackSize;

		Node* min_top; //min을 위한 또다른 linked list

};

void printStack(Stack* s){
	while(!s->isEmpty()){
		int p = s->pop();
		cout << p << ", ";
	}
	cout << endl;
}




int main(){
	Stack* s = new Stack();
	s->push(2);
	s->push(4);

	cout << "2 should be printed: " << s->min() << endl;

	s->push(1);
	cout << "1 should be printed: " << s->min() << endl;
	s->push(5);
	s->push(1);
	s->push(9);
	cout << "1 should be printed: " << s->min() << endl;

	cout << "pop start" << endl;
	s->pop();
	cout << "1 should be printed: " << s->min() << endl;
	s->pop();
	s->pop();
	cout << "1 should be printed: " << s->min() << endl;

	cout << "Pushed in order of 2, 4, 1, 5, 9! Therefore, currently 9 is at the top!//142" << endl;

	printStack(s);

	cout << s->isEmpty() << endl;

}

/*
template<typename T>
class StackMin{
	public:
		template<typename U>
		void push(U &&value){
			if(minStack.isEmpty() || value <= minStack.peek())
				minStack.push(value);
			stack.push(forward<U>(value));
		}

		T& peek(){ return stack.peek();}

		T& min(){return minStack.peek();}

		T pop(){
			auto value = stack.pop();
			if(value == min()) minStack.pop();
			return value;
		}

		bool isEmpty(){return stack.isEmpty();}

	private:
		Stack<T> stack;
		Stack<T> minStack;
};
*/

/*
int main(){
	StackMin<int> stack;
	for(auto v:{5,10,4,9,3,3,8,2,2,7,6}){
		stack.push(v);
		cout << "Pushed value: " << v << ", min value: " << stack.min() << endl << endl;
	}

	while(!stack.isEmpty()){
		auto v = stack.pop();
		cout << "Popped value: " << v;
		if(stack.isEmpty()) cout << ", stack is empty" << endl;
		else cout << ", min value: " << stack.min() << endl;
	}
	return 0;
}

*/

