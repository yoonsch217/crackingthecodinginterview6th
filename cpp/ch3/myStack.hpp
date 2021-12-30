#include <iostream>

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
            return rtn;
        }

        void push(int i){ 
            Node* tmp = new Node(i, top);
//          tmp->next = top;
            top = tmp;
            stackSize++;
        }

        bool isEmpty(){
            return (stackSize == 0 || top == nullptr);
        }

        int peek(){
            if(isEmpty()) return -217;
            return top->data;
        }

 //   private:
        Node* top;  //head를 top으로 본다. push할 때 head에 추가. head를 바꿔야되네.
        int stackSize;

};

void printStack(Stack* s){ 
    while(!s->isEmpty()){
		int p = s->pop();
		cout << p << ", ";
	}
	cout << endl;
}

void peekAndPrint(Stack* s){
	Node* tmp = s->top;
	while(tmp!=nullptr){
		cout << tmp->data << "-->";
		tmp = tmp->next;
	}
	cout << "nullptr" << endl;
}
