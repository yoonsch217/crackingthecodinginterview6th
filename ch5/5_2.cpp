#include <iostream>
#include <string>

using namespace std;

string toBinary(double input){

	if(input > 1 || input < 0) return "Error";

	string rtn = "0.";

	cout << "start!! " << endl;

	while(input > 0){
		cout << "first loop" << endl;
		if (rtn.length() > 32) return "error!";

		input *= 2;

		if(input >= 1){
			rtn.append("1");
			input--;
		} else rtn.append("0");
	}

	return rtn;

}

int main(){

	double d = 0.75;
	cout << d << endl;
	
	cout << toBinary(d) << endl;
}
