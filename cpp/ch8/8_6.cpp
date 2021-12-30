#include <iostream>
using namespace std;

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod){
	if(n==1){
		cout << "Move disk 1 from rod " << from_rod << "to rod " << to_rod << endl;
		return;
	}

	towerOfHanoi(n-1, from_rod, aux_rod, to_rod);
	cout << "Move dist " << n << " from rod " << from_rod << " to rod " << to_rod << endl;
	towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}

int main(){
	int n = 3;
	towerOfHanoi(n, 'A', 'C', 'B');
	return 0;
}


/*
3 a c b
 2 a b c
  1 a c b
   cout
  1 c b a

 cout 

 2 b c a
  1 




   */
