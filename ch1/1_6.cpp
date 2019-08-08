#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;


string compress(string s){
	char rtn[s.length()];

	int idx = 0;
	int rtn_idx = 0;
	int count = 0;

	char c = s.at(0);
//	bool isNew = true;

	cout << rtn_idx << endl;
	rtn[rtn_idx++] = c;
	cout << rtn_idx << endl;



	for(int i = 0; i < s.length(); i++){
//		if(isNew){
//			c = s.at(i);
//			rtn[rtn_idx] = c;
//		}

//		else{

		if (rtn_idx > s.length()){
			printf("length overflowed \n");
			return s;

		}
		if(s.at(i) == c){
			count++;
		}
		else{
			rtn[rtn_idx++] = (char)(count);

			c = s.at(i);
			count = 1;

//			}
		}

	}

	return rtn;
	
}

int main(){
	char input[100];


	int test = 5;
	char test_c[2];
	string temp = to_string(test);
	test_c[0] = temp.at(0);

	test_c[1] = 'A';
	printf("This is test... %s \n ", test_c);

	printf("start program! \n");
	scanf("%s", input);

	printf("%s \n", compress(input).c_str());

}
