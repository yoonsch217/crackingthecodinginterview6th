#include <iostream>
#include "myStack.hpp"

using namespace std;

Stack* sortStack(Stack* s){
	Stack* tmp = new Stack();

	int curr;
	int cnt = 0;

	while(!s->isEmpty()){
		curr = s->pop();

		if(tmp->isEmpty()) {
			tmp->push(curr);
//			cout << "At first, push to the empty stack \"tmp\"" <<  endl;
		}
		else{
			while(!tmp->isEmpty() && tmp->peek() > curr){
				s->push(tmp->pop());
				cnt++;
//				cout << "push to s, and increase cnt to " << cnt << endl;
			}
			tmp->push(curr);
//			cout << "push curr to tmp" << endl;
			while(cnt>0){
				tmp->push(s->pop());
				cnt--;
//				cout << "repush to tmp, and decrease cnt to " << cnt << endl;
			}
		}
		
	}

	return tmp;

}


int main(){

	Stack* s = new Stack();

	s->push(5);
	s->push(2);
	s->push(7);
	s->push(6);
	s->push(5);
	s->push(1);

	cout << "before sorting: " << endl;
	peekAndPrint(s);
	peekAndPrint(s);

	cout << "after sorting: " << endl;
	peekAndPrint(sortStack(s));


}
