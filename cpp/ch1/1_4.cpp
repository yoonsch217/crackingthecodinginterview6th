#include <stdio.h>
#include <string>

using namespace std;

bool isPalindrome(string s){
	int ascii[128];
	for(int i = 0; i <128; i++) ascii[i] = 0;

	for(int i = 0; i < s.length(); i++){
		if(s.at(i) == ' ') continue;
		ascii[s.at(i)]++;
	}

	int cnt = 0;

	for(int i = 0; i < 128; i++){
		if(ascii[i]%2 == 1) cnt++;
		if(cnt >= 2) return false;
	}

	return true;

}

int main(){
	char input[100];

	scanf("%s", input);

	if(isPalindrome(input)) printf("yes\n");
	else printf("no\n");

}
