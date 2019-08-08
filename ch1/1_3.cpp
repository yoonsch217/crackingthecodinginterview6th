#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

string replaceSpace(string s, int n){

	printf(" in the replace function\n");

	char buffer[100];

	cout << "input length is " << s.length() << endl;
	
	
	int index = 0;

	for(int i = 0; i < s.length(); i++){
		if(s.at(i) != ' '){
			buffer[index] = s.at(i);
			index++;
			cout << "from if condition  " << index << endl;
		}
		else{
			buffer[index++] = '%';
			buffer[index++] = '2';
			buffer[index++] = '0';

			cout << "from else condition   " << index << endl;
		}
	}

	cout << "just before the return!! " << endl;
	return buffer;
}

int main(){

	char input[100];

	scanf("%s", input);

	string input2 = "a bcd";


	printf("%s \n", replaceSpace(input2, 100).c_str());

}
