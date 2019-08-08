#include <iostream>
using namespace std;

int numOfFlip(int a, int b){

	int count = 0;

	for(int c = a^b; c!=0; c&=(c-1)) count++;

	return count;
}

int main(){
	int a;
	int b;
	cin >> a;
	cin >> b;

	cout << numOfFlip(a,b) << endl;

}
