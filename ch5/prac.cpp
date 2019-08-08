#include <iostream>

using namespace std;

int main(){

	int a;
	unsigned int b;

	cout << "input 1:" << endl;
	cin >> a;
	b = a;

//	cout << "input 2:" << endl;
//	cin >> b;


	cout << "simple <<: " << (a>>1) << endl;

	cout << "unsinged <<: " << (b>>1) << endl;

	int result = a^b;
	cout << result << endl;

}
