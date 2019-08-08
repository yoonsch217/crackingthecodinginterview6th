#include <stdio.h>
#include <string>

using namespace std;

bool isPermut(string s1, string s2){
	if(s1.length() != s2.length()) return false;

	int buf1[128];
	int buf2[128];
	for(int i = 0; i<128; i++){
		buf1[i] = 0;
		buf2[i] = 0;
	}


	for(int i = 0; i < s1.length(); i++){
		buf1[s1.at(i)]++;
		buf2[s2.at(i)]++;
	}

	for(int i = 0; i < s1.length(); i++){
		if(buf1[i] != buf2[i]) {
			printf("%d  %d   %d ", i, buf1[i], buf2[i]);
			return false;
		}

	}

	return true;

}


int main(){

	char input1[100];
	char input2[100];
	scanf("%s", input1);
	scanf("%s", input2);

	if(isPermut(input1, input2)) printf("true \n");
	else printf("false \n");



}
