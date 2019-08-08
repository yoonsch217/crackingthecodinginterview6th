#include <iostream>
#include <bitset>
#include <algorithm>

using namespace std;

//My code
//Find continuos 1s and figure out each length.
//If two lengths are just one bit away, add the two lengths.
//Otherwise, just increase by 1.
//Compare those values.

int flipBit(int i){
	bitset<16> bs(i);

	int comp = 0;
	int cnt = 0;
	int max_value = 0;

	while(bs != 0){

		if(bs[0] == 0){
			max_value = max(max_value, cnt+1+comp);
			comp = cnt;
			cnt = 0;
		}
		else{
			cnt++;
		}
		bs = bs >> 1;
	}
	max_value = max(max_value, cnt+1+comp);
	return max_value;
}


int main(){
	int input;
	cin >> input;
	int ans = flipBit(input);

	cout << "The answer is " << ans << endl;
	return 0;

}
