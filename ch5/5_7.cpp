#include <iostream>

using namespace std;

int pairSwitch(int x){

	return ((x&(0xaaaaaaaa))>>1) | ((x&(0x55555555))<<1);
}

int main(){
	int x;
	cin >> x;
	cout << pairSwitch(x) << endl;
	
	return 0;
}
