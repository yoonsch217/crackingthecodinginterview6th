
//#1

func(Node* n){
	if(n == nullptr || n->next == nullptr) return;

	Node* curr = n;
	Node* check = n;
	while(curr != nullptr){
		while(check->next != nullptr){
			if(curr->data == check->next->data) check->next = check->next->next;
			else check = check->next;
		}
		curr = curr->next;
	}

}

func(Node* n){
	if(false) return;

	set<int> s;
	s.insert(n->data);

	Node* curr = n;

	while(curr != nullptr){
		
	}
}

//#2

func(Node* n, int k){
	if(false) return;

	Node* r1 = n;
	Node* r2 = n;

	for(int i = 0; i < 7; i++){
		r2 = r2->next;
		if() return;
	}

	while(r2 != nullptr){
		r1++;
		r2++
	}

	return r1;
}


//////////////////////////recursive!!!!
func(Node* n, int k){
		
}



//#3
trivial


//#4   Chosen for PT!!
Node* paritition(Node* n, int x){
	if(false) return;

	Node* curr = n;

	Node* head = n;

	if(curr->next->data < x){
		Node* tmp = curr->next;
		curr->next = curr->next->next;
		tmp->next = head;
		head = tmp;
	}
	else{
		curr = curr->next;
	}

	return head;
}



//#5
N* func(N* n1, N* n2){
	
	N* rtn = new N;
	rtn->next = nullptr;

	N* curr = rtn;

	int carry;

	while(n1 != nullptr || n2 != nullptr){
		if(n1 == nullptr) {
			curr->data = n2.data+carry > 10 ? %10 : ;
			if > 10 carry = 1;
			else carry = 0;
			continue;
		}
		curr->data = n1.data+n2.data+carry > 10 ? n1.data+n2.data % 10 : n1.data + n2.data;
		if >10 carry = 1;
		else carry = 0;

		curr = curr->next;

	}

	return rtn;


}

//////////////////WRONG!!!



//#6

bool isPalindrome_stack(Node* n){
	if(false) return;

	stack<Node*> s;

	Node* r1 = n;
	Node* r2 = n;

	while(r2 != nullptr// || r2->next != nullptr){  //wrong
		s.push(r1->data);
		r1 = r1->next;
		r2 = r2->next->next;
	}
	if(r2->next == nullptr) int t = s.pop();//r1 = r1->next;

	while(r1 != nullptr){
		if(r1.data != s.pop() return false;
		r1 = r1->next;
	}
	return true;
}

}


//////////////////recursive form!



//#7

func(n1, n2){
	l1 = n1.length;
	l2 = n2.length;

	r1 = new n;
	r2 = new n;
	int diff;
	if(l1>l2)
		r1 = n1;
		diff = l1 - l2;

	while() r2 -> next;

	while()
	if(r1 == r2)
		return r1;

	return nullptr;

}



:








