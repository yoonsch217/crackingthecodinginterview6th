#include <iostream>

using namespace std;

int magicSlow(int array[]){
	for(int i = 0; i < sizeof(array)/sizeof(*array); i++){
		if(array[i]==i) return i;
	}
	return -1;

}
int magicFast(int array[], int start, int end){
	if(end < start) return -1;

	int mid = (start+end)/2;

	if(array[mid]==mid) return mid;
	else if(array[mid]>mid) return magicFast(array, start, mid-1);
	else return magicFast(array, mid+1, end);
}


int magicFast(int array[]){
	return magicFast(array, 0, sizeof(array)/sizeof(*array)-1);
}

int main(){
	cout << "Umm.." << endl;

	return 0;
}
