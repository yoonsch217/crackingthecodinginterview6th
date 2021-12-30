#include <iostream>

using namespace std;

int minProduct(int a, int b);
int minProductHelper3(int a, int b);

int minProductHelper(int smaller, int bigger){
	if(smaller == 0) return 0;
	else if(smaller == 1) return bigger;

	int s = smaller>>1; //divide by 2
	int side1 = minProduct(s, bigger);
	int side2 = side1;
	if(smaller % 2 == 1) side2 = minProductHelper(smaller-s, bigger);

	return side1+side2;
}


int minProduct(int a, int b){
	int bigger = a<b? b:a;
	int smaller = a<b? a:b;
	return minProductHelper(smaller, bigger);
}

/////

int minProduct2(int smaller, int bigger, int memo[]){
	if(smaller==0) return 0;
	else if(smaller == 1) return bigger;
	else if(memo[smaller] > 0) return memo[smaller];

	int s = smaller>>1;
	int side1 = minProduct2(s, bigger, memo);
	int side2 = side1;
	if(smaller%2==1) side2=minProduct2(smaller-s, bigger, memo);

	memo[smaller] = side1+side2;
	return memo[smaller];
}


int minProduct2(int a, int b){
	int bigger = a<b? b:a;
	int smaller = a<b? a:b;

	int memo[smaller+1];
	return minProduct2(smaller, bigger, memo);
}


/////


int minProduct3(int a, int b){
	int bigger = a<b? b:a;
	int smaller = a<b? a:b;
	return minProductHelper3(smaller, bigger);
}

int minProductHelper3(int smaller, int bigger){
		if(smaller==0)return 0;
		else if(smaller==1) return bigger;

		int s = smaller>>1;
		int halfProd = minProductHelper3(s, bigger);

		if(smaller%2==0) return halfProd+halfProd;
		else return halfProd+halfProd+bigger;
	
}

int main(){


	return 0;
}
