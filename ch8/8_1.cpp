#include <iostream>

using namespace std;

int countWays1(int n){
	if(n<0) return 0;
	else if(n==0) return 1;
	else return countWays1(n-1)+countWays1(n-2)+countWays1(n-3);
}



int countWays2(int n, int memo[]){
	if(n<0) return 0;
	else if(n==0) return 1;
	else if(memo[n-1] > -1) return memo[n-1];
	else{
		memo[n-1] = countWays2(n-1, memo) + countWays2(n-2, memo) + countWays2(n-3, memo);
		return memo[n-1];
	}
}

int countWays2(int n){
	int memo[n];
	for(int i = 0; i < n; i++) memo[i] = -1;
	return countWays2(n, memo);
}



int main(){
	int input;

	cin >> input;

	cout << "With Memoization Solution: " << countWays2(input) << endl;
	cout << "Brute Force Solution: " << countWays1(input) << endl;

	return 0;

}
