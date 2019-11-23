#include <iostream>

using namespace std;

class Node;

class Node{
	public:
		int data;

		Node left;

		Node(int d){
			data = d;
		}
};


int main(){
	Node n(10);

	cout << n.data << endl;
	
}
