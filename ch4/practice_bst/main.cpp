#include <iostream>
#include "tree.hpp"

using namespace std;

int main(int argc, char* argv[]){
	BinarySearchTree<int> bst;

	function<int(int&, int&)> comparator = [](int& lhs, int& rhs)->int{
		if(lhs > rhs) return 1;
		else if(lhs < rhs) return -1;
		else return 0;
	};

	function<void(int& value)> printer = [](int& value)->void{
		cout << value << endl;
	};

	bst.insert(3, comparator);
	bst.insert(2, comparator);
	bst.insert(5, comparator);
	bst.insert(4, comparator);
	bst.insert(6, comparator);

	bst.remove(5, comparator);
	bst.traverse_pre_order(printer);

	return 0;
}


