#include <iostream>

using namespace std;

void merge(int arr1[], int len1, int arr2[], int len2){
	int idx1 = len1 - 1;
	int idx2 = len2 - 1;
	int idx_merged = len1 + len2 - 1;

	while(idx2 >= 0){
		if(idx1 >= 0 && arr1[idx1] > arr2[idx2]){
			arr1[idx_merged] = arr1[idx1];
			idx1--;
		}
		else{
			arr1[idx_merged] = arr2[idx2];
			idx2--;
		}
		idx_merged--;
	}

}


int main(){
	int arr1[20];
	for(int i = 0; i < 5; i++) arr1[i] = 2*i + 1;
	int arr2[5] = {2,4,6,8,10};

	merge(arr1, 5, arr2, 5);

	for(int i = 0; i < 20; i++) cout << arr1[i] << " ";
	cout << endl;

}
