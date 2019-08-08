#include <stdio.h>
#include <string>
//#include <string.h>

using namespace std;

bool isUnique(string s){
	int ascii[128];
	for(int i = 0; i < 128; i++) ascii[i]=0;

	/*
	char buffer[s.length()];
	strcpy(buffer, s.c_str());
	
	for(int i = 0; i < s.length(); i++){
		int index = (int)(buffer[i]);
		ascii[index]++;
		if(ascii[index] >=2) return false;
	}
	*/

	for(int i = 0; i < s.length(); i++){
		int index = (int)(s.at(i));
		ascii[index]++;
		if(ascii[index] >= 2) return false;
	}
	return true;

}



int main(){

	char input[100];

	scanf("%s", input);

	if(isUnique(input)) printf("yes");
	else printf("no");
}
