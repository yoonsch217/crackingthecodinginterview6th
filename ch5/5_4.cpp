//getNext: 맽 밑 block이 아닌 가장 낮은 위치의 0을 1로 바꾸고 그 밑에는 원래의 1개수 - 1 만큼을 밑에서부터 채운다.
//getPrev: 맨 밑 block이 아닌 가장 낮은 위치의 1을 0으로 바꾸고 그 밑에는 원래의 1개수 + 1을 맨위부터 채운다.
#include <iostream>
#include <bitset>

using namespace std;


int getNext_BF(int i){
	//bitset<16> bs(i);

	int c = i;
	int c0 = 0;
	int c1 = 0;
	while((c&1)==0 && (c!=0)){
		c0++;
		c>>=1;
	}

	while((c&1)==1){
		c1++;
		c >>= 1;
	}

	if(c0+c1 == 31 || c0+c1==0) return -1;

	int p = c0 + c1;

	i |= (1<<p);
	i &= ~((1<<p)-1);
	i |= (1<<(c1-1))-1;

	return i;
}

int getPrev_BM(int i){
	int tmp = i;
	int c0 = 0;
	int c1 = 0;
	while(tmp&1==1){
		c1++;
		tmp>>=1;
	}

	if(tmp==0) return -1;

	while(((tmp&1)==0)&&(tmp!=0)){
		c0++;
		tmp>>=1;
	}

	int p = c0+c1;
	i&=((~0)<<(p+1));

	int mask = (1<<(c1+1))-1;
	i|=mask<<(c0-1);

	return i;

}


//int getNext_A(int i){
	



int main(){
	int input;
	cin  >> input;
	int ans = getNext_BF(input);

	cout << "The answer is " << ans << endl;

	return 0;

}
