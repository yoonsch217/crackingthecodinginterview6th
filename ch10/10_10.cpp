#include <iostream>

using namespace std;


class RankNode{
	public:
		int left_size = 0;
		int data = 0;
		RankNode* left;
		RankNode* right;

		RankNode(int d){ data = d;}

		void insert(int d){
			if(d<=data){
				if(left != nullptr) left->insert(d);
				else left = new RankNode(d);
				left_size++;
			}
			else{
				if(right != nullptr) right->insert(d);
				else right = new RankNode(d);
			}
		}

		int getRank(int d){
			if(d==data) return left_size;

			else if(d < data){
				if(left == nullptr) return -1;
				else return left->getRank(d);
			}
			else{
				int right_rank = right == nullptr ? -1 : right->getRank(d);
				if(right_rank == -1) return -1;
				else return left_size + 1 + right_rank;
			}
		}
};

RankNode* root = new RankNode(10);

void track(int number){
	if(root == nullptr) root = new RankNode(number);
	else root->insert(number);
}

int getRankOfNumber(int number){
	return root->getRank(number);
}


int main(){

	root->insert(5);
	root->insert(15);
	root->insert(8);
	root->insert(25);
	root->insert(5);
	root->insert(1);

	cout << getRankOfNumber(15) << endl;
}
