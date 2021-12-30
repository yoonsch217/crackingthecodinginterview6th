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

		//
		void setBottomStack(Stack* s){
			bottomStack = s;
		}

		Stack* getBottomStack(){
			return bottomStack;
		}

		int getSize(){
			return stackSize;
		}

    private:
        Node* top;  //head를 top으로 본다. push할 때 head에 추가. head를 바꿔야되네.
        int stackSize;

		//
		Stack* bottomStack = nullptr;

};

class SetofStacks{
	public:

		SetofStacks(int cap) : capacity(cap), topStack(nullptr), stackNum(0) {}

		void push(int i){
			if(isEmpty() || topStack->getSize() == capacity ){
				Stack* tmp = new Stack();
				tmp->push(i);
				tmp->setBottomStack(topStack);
				topStack = tmp;
				stackNum++;

			}
			else{
				topStack->push(i);
			}
		}

		int pop(){
			if(isEmpty()) return -217;

			int rtn = topStack->pop();
			if(topStack->isEmpty()){
				topStack = topStack->getBottomStack();
				stackNum--;
			}
			return rtn;
		}

		int peek(){
			return 0;//skip~
		}

		bool isEmpty(){
			return (topStack==nullptr && stackNum == 0);

		}

		int getStackNum(){
			return stackNum;
		}

		int getCapacity(){
			return capacity;
		}

		//follow up
		int popAt(int idx){
			Stack* tmp = topStack;
			while(idx >0){
				tmp = tmp->getBottomStack();
				idx--;
				
			}
			return tmp->pop();
		}

	private:
		Stack* topStack;
		int capacity;
		int stackNum;
//		int currStackSize;
};


int main(){
	SetofStacks* s = new SetofStacks(3);

	cout << "start!!" << endl;
	cout << "Capacity is set to: " << s->getCapacity() << endl;

	if(s->isEmpty()) cout << "Currently empty!" << endl;
	else cout << "Initializing wrong" << endl;
	
	for(int i = 0; i < 20; i++){
		s->push(i);
	}

	
	cout << "push finished!" << endl;

	cout << "Pop at 4:  " << s->popAt(4) << endl;

	int cnt = 0;

	while(!s->isEmpty()){
		cout << cnt << ": popped value is " << s->pop() << " , and the number of stacks is " << s->getStackNum() <<  endl;
	}



}

