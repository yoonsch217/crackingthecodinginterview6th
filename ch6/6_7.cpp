#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
	int male = 0;
	int female = 0;

	int testCases;
	cin >> testCases;

	for(int i = 0; i < testCases ; i++){
		while(rand()%2 == 0){
			male++;
		}
		female++;
	}

	printf("Male: %d \nFemale: %d\n", male, female);

	return 0;




}

/*
M : 1/2 , F: 1/2
//////
F 1/2
MF 1/4
MMF 1/8
MMMF 1/16
.
.
F*(1/2 + 1/4 + 1/8 + ...)
M*(1/4 + 2/8 + 3/16 + ...)
F: 1/2^n
M: n/2^(n+1)
*/
