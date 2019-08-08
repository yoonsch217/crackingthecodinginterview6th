#include <iostream>

#include <utility>

using namespace std;




///////////////////////////


class myStack{
	public:
		bool isEmpty(int stackIdx);
		bool isFull(int stackIdx);

		void push(int stackIdx, int value);
		int pop(int stackIdx);



	private:
		int stackNum = 3;
		int[] values;
		int[] stackSize;

};



///////////stack
template <typename T>
class Stack{
	public:
		Stack(): top(nullptr), stackSize(0){}

		Stack(Stack &&other): top(move(other.top)), stackSize(move(other.stackSize)){}

		~Stack(){
			while(!isEmpty()) pop();
		}

		template <typename U>
		void push(U &&value){
			auto n = new Node(forward<U>(value), top);
			top = n;
			++stackSize;
		}

		T &peek(){
			if(!top) throw StackIsEmptyException();
			return top->value;
		}

		T pop(){
			if(!top) throw StackIsEmptyException();
			auto value(move(top->value));
			auto n = top;
			top = n->next;
			delete n;
			--stackSize;
			return value;
		}

		bool isEmpty() const{ return stackSize;}

		class StackIsEmptyException{};

	private:
		struct Node{
			Node(T &&v, Node *n): value(move(v)), next(n){}

			Node(const T& v, Node* n): value(v), next(n){}

			T value;
			Node* next;
		};

		Node* top;
		size_t stackSize;
};


